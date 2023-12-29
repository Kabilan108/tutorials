"use strict"

const express = require("express");
const app = express();
const port = 3000;

// serve static files
app.use(express.static("public"));

app.get("/hello", (req, res) => {
    res.send("Hello World!");
});

app.listen(port, () => {
    console.log(`Server listening at http://localhost:${port}`)
});
