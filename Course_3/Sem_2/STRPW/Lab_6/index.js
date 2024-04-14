import express from 'express';
import bodyParser from 'body-parser';
import path from 'path';
import { PrismaClient } from '@prisma/client';
import multer from 'multer';
import fs from 'fs';
import turtleRoutes from "./routes/turtleRoutes.js";
import { fileURLToPath } from 'url';
import pizzaRoutes from "./routes/pizzaRoutes.js";
import weaponRoutes from "./routes/weaponRoutes.js";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const prisma = new PrismaClient();
const upload = multer({ dest: 'images/' });
const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));


app.use('/api/turtles', turtleRoutes);
app.use('/api/pizzas', pizzaRoutes);
app.use('/api/weapons', weaponRoutes);

app.get('/', async (req, res) => {
    try {
        res.sendFile(path.join(__dirname, 'turtles.html'));
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});


app.get('/upload', (req, res) => {
    res.sendFile(__dirname + '/upload.html');
});

app.post('/upload', upload.single('image'), async (req, res) => {
    const turtleId = req.body.turtleId;
    const image = req.file;

    try {
        const turtle = await prisma.turtles.findUnique({ where: { id: parseInt(turtleId) } });
        if (!turtle) {
            throw new Error('Такая черепашка-ниндзя не существует');
        }

        const imageFileName = `images/turtle_${turtleId}.jpg`;
        fs.renameSync(image.path, imageFileName);
        await prisma.turtles.update({
            where: { id: parseInt(turtleId) },
            data: { image: imageFileName }
        });
        

        res.send('Изображение успешно загружено и данные обновлены!');
    } catch (err) {
        res.status(400).send(err.message);
    }
});

app.use('/images', (req, res, next) => {
    const imagePath = path.join(__dirname, 'images', req.url);
    fs.access(imagePath, fs.constants.F_OK, (err) => {
        if (err) {
            res.status(404).send('Not found');
        } else {
            next();
        }
    });
}, express.static(path.join(__dirname, 'images')));


const main = async ()=>{
    try {
        await prisma.$connect();
        app.listen(3000, () => {
            console.log('Server is running on port 3000');
        });
    }
    catch (e) {
        console.error(e);
        prisma.$disconnect();
        process.exit(1);
    }
}

main();



