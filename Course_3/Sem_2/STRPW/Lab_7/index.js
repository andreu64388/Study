import express from "express";
import { Server } from "socket.io";
import http from "http";
import path from "path";


const __dirname = path.resolve();
const HTTP_PORT = 3000;
const WS_PORT = 4000;

const app = express();
const httpServer = http.createServer(app);

const io = new Server(httpServer, {
    cors: {
        origin: "*",
    },
});

const checkStartRequested = (req, res, next) => {
    if (req.path === "/start" && req.method === "GET") {
        next();
    } else {
        console.log("Bad request");
        res.status(400).send("Bad request");
    }
};

app.use(checkStartRequested);
app.get("/start", checkStartRequested, (req, res) => {
    res.sendFile(path.resolve(__dirname, "index.html"));
});



io.on("connection", (socket) => {
    console.log("New user connected");

    socket.on("joinRoom", ({ username }) => {
        console.log("User joined:", username);
        socket.username = username;
        socket.broadcast.emit("message", { user: "Server", text: `${username} has joined the chat` });
    });

    socket.on("message", (message) => {
        console.log("Message received:", message, "from", socket.username);
        io.emit("message", { user: socket.username, text: message });
    });


    socket.on("leaveRoom", () => {
        io.emit("message", { user: "Server", text: `${socket.username} has left the chat` });

    });

});

httpServer.listen(HTTP_PORT , () => {
    console.log(`HTTP Server is running on port ${HTTP_PORT}`);
});

io.listen(WS_PORT);
console.log(`WS Server is running on port ${WS_PORT}`);
