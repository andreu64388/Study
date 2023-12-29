const express = require("express");
const sqlite3 = require("sqlite3");
const path = require("path");

const app = express();
const port = 3000;

app.use(express.urlencoded({ extended: true }));
app.use(express.static("public"));

const dbPath = path.resolve(__dirname, "cars.db");
const db = new sqlite3.Database(dbPath);

app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

app.get("/", (req, res) => {
  res.render("home");
});

app.post("/api/cars", (req, res) => {
  const { make, model, year, price } = req.body;
  const query =
    "INSERT INTO cars (make, model, year, price) VALUES (?, ?, ?, ?)";
  db.run(query, [make, model, year, price], (err) => {
    if (err) {
      console.error(err.message);
      res.status(500).send("Internal Server Error");
      return;
    }
    res.redirect("/cars");
  });
});

app.get("/cars", (req, res) => {
  db.all("SELECT * FROM cars", (err, cars) => {
    if (err) {
      console.error(err.message);
      res.status(500).send("Internal Server Error");
      return;
    }
    res.render("cars", { cars });
  });
});

app.get("/customers", (req, res) => {
  db.all("SELECT * FROM customers", (err, customers) => {
    if (err) {
      console.error(err.message);
      res.status(500).send("Internal Server Error");
      return;
    }
    res.render("customers", { customers });
  });
});

app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});
