// сервер-посредник

const udp = require("dgram");
const server = udp.createSocket("udp4");
const port = 7777;
const host = "0.0.0.0";
const config = require("./config.json");
const Commands = require("./commands");

let coordinator = null;
let awaitingClients = [];

server.on("message", (msg, info) => {
  let obj = JSON.parse(msg.toString());

  if (obj.command === Commands.get) {
    if (coordinator) {
      const params = JSON.stringify({ command: Commands.get });

      server.send(params, 5555, coordinator, (error) => {
        if (error) {
          server.close();
        } else {
          console.log("get time");
        }
      });
      awaitingClients.push(info);
    } else {
      console.log("coordinator not initialised");
    }
  } else if (obj.command === Commands.connect) {
    coordinator = obj.ip;
    console.log("coordinator: ", coordinator);
  } else if (obj.command === Commands.time) {
    if (awaitingClients.length === 0) {
      return;
    }

    for (const client of awaitingClients) {
      server.send(obj.time, client.port, client.address, (error) => {
        if (error) {
          console.log("sending time to client error");
        } else {
          console.log("send time");
        }
      });
    }

    awaitingClients = [];
  }
});

server.on("listening", function () {
  console.log("Server is listening at port: " + server.address().port);
  console.log("Server ip: " + config.mainServer);
});

server.on("close", function () {
  console.log("Socket is closed !");
});

server.on("error", function (error) {
  console.log("Error: " + error);
  server.close();
});

server.bind(port, host);
