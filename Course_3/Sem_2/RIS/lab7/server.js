// сервер UDP
const udp = require("dgram");
const server = udp.createSocket("udp4");
const port = 5555;
const host = "0.0.0.0";
const servers = new Set();
const timeOut = 10000;
const config = require("./config.json");
const Commands = require("./commands");

let addressLocal;
let lastOctet;
let coordinator = null;
let timerWaitRejects;
let timerWaitPong;
let timerIntervalPing;
server.on("message", (msg, info) => {
  if (info.address === config.localServer) {
    return;
  }

  console.log("Data received from client : " + msg.toString());
  console.log(
    "Received %d bytes from %s:%d\n",
    msg.length,
    info.address,
    info.port
  );

  msg = JSON.parse(msg.toString());

  if (msg.command === Commands.voting) {
    reject(info);
    voting();
  } else if (msg.command === Commands.ok) {
    waitResponses(Commands.cancel);
  } else if (msg.command === Commands.won) {
    setCoordinator(info.address);
    clearInterval(timerIntervalPing);
    timerIntervalPing = setInterval(() => pingCoordinator(info), timeOut);
  } else if (msg.command === Commands.ping) {
    ping(info);
  } else if (msg.command === Commands.pong) {
    pong(info);
  } else if (msg.command === Commands.get) {
    sendTime();
  } else if (msg.command === Commands.hello) {
    handleHello(info);
  } else if (msg.command === Commands.helloResponse) {
    handleHelloResponse(info);
  }
});

const handleHello = (info) => {
  console.log("Handle hello to " + info.address);

  const params = JSON.stringify({ command: Commands.helloResponse });
  server.send(params, 5555, info.address, (error) => {
    if (error) {
      console.log(`Hello response error`);
    }
  });
};

const handleHelloResponse = (info) => {
  console.log("Hello response from " + info.address);
  if (
    servers.has(info.address) !== true &&
    info.address !== config.localServer
  ) {
    console.log("Add new server " + info.address);
    servers.add(info.address);
    voting();
  }
};

server.on("listening", function () {
  addressLocal = config.localServer;
  lastOctet = addressLocal.split(".")[3];
  console.log("Server is listening at port: " + server.address().port);
  console.log("Server ip: " + addressLocal);
  voting();
});

server.on("close", function () {
  console.log("Socket is closed !");
});

server.on("error", function (error) {
  console.log("Error: " + error);
  server.close();
});

let voting = () => {
  const params = JSON.stringify({ command: Commands.voting });

  servers.forEach((address) => {
    if (Number.parseInt(lastOctet) < Number.parseInt(address.split(".")[3])) {
      server.send(params, 5555, address, (error) => {
        if (error) {
          console.log(error);
        } else {
          console.log("vote sent : " + address);
        }
      });
    }
  });

  clearInterval(timerIntervalPing);
  waitResponses(Commands.run);
};

let reject = (info) => {
  const params = JSON.stringify({ command: Commands.ok });

  server.send(params, 5555, info.address, (error) => {
    if (error) {
      console.log(error);
    } else {
      console.log("ok sent : " + info.address);
    }
  });
};

let waitResponses = (command) => {
  const params = JSON.stringify({ command: Commands.won });

  if (Commands.run === command) {
    timerWaitRejects = setTimeout(() => {
      setCoordinator(addressLocal);
      servers.forEach((address) => {
        server.send(params, 5555, address, (error) => {
          if (error) {
            console.log(error);
          } else {
            console.log("won sent : " + address);
          }
        });
      });
    }, 5000);
  } else if (Commands.cancel === command) {
    clearTimeout(timerWaitRejects);
  }
};

const pingCoordinator = (info) => {
  console.log("pingCoordinator");
  const params = JSON.stringify({ command: Commands.ping });

  server.send(params, 5555, coordinator, (error) => {
    if (error) {
      servers.delete(info.address);
      voting();
    } else {
      timerWaitPong = setTimeout(() => voting(), 4000);
    }
  });
};

const ping = (info) => {
  console.log("ping");
  const params = JSON.stringify({ command: Commands.pong });

  server.send(params, 5555, info.address, (error) => {
    if (error) {
      console.log(error);
    }
  });
};

const pong = (info) => {
  console.log("pong");
  clearTimeout(timerWaitPong);
  /*    if (servers.has(info.address) !== true && info.address !== config.localServer) {
        servers.add(info.address);
        voting();
    }*/
};

let setCoordinator = (ip) => {
  coordinator = ip;
  connect();
  console.log("set ip %s", ip);
};

let connect = () => {
  const params = JSON.stringify({ command: Commands.connect, ip: coordinator });

  server.send(params, 7777, config.mainServer, (error) => {
    if (error) {
      console.log(error);
    } else {
      console.log("sent connect");
    }
  });
};

let sendTime = () => {
  const time = JSON.stringify({
    command: Commands.time,
    time: new Date().toString(),
  });

  server.send(time, 7777, config.mainServer, (error) => {
    if (error) {
      console.log(error);
    } else {
      console.log("sent time");
    }
  });
};

server.bind(port, host);

setInterval(() => {
  server.setBroadcast(true);
  console.log("Find servers");
  const params = JSON.stringify({ command: Commands.hello });

  server.send(params, 0, params.length, 5555, "192.168.165.118", (error) => {
    if (error) {
      console.log(`Sent broadcast error`);
    }
    server.setBroadcast(false);
  });
}, 10000);
