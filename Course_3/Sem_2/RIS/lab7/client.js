const udp = require("dgram");
const client = udp.createSocket("udp4");
const config = require("./config.json");
const Commands = require("./commands");
const port = 9999;

client.bind(port, "192.168.165.138");

client.on("message", (msg, info) => {
  console.log("Data received from server : " + msg.toString());
  console.log(
    "Received %d bytes from %s:%d\n",
    msg.length,
    info.address,
    info.port
  );
});

setInterval(() => {
  const params = JSON.stringify({ command: Commands.get });

  client.send(params, 7777, config.mainServer, (error) => {
    if (error) {
      client.close();
    } else {
      console.log("get time");
    }
  });
}, 3000);
