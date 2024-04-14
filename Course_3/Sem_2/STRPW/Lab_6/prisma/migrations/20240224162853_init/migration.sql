-- CreateTable
CREATE TABLE "Pizzas" (
    "id" SERIAL NOT NULL,
    "name" TEXT NOT NULL,
    "calories" INTEGER NOT NULL,
    "description" TEXT NOT NULL,

    CONSTRAINT "Pizzas_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Weapons" (
    "id" SERIAL NOT NULL,
    "name" TEXT NOT NULL,
    "dps" INTEGER NOT NULL,

    CONSTRAINT "Weapons_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Turtles" (
    "id" SERIAL NOT NULL,
    "name" TEXT NOT NULL,
    "weaponId" INTEGER NOT NULL,
    "favoritePizzaId" INTEGER NOT NULL,
    "color" TEXT NOT NULL,
    "image" TEXT NOT NULL,

    CONSTRAINT "Turtles_pkey" PRIMARY KEY ("id")
);

-- CreateIndex
CREATE UNIQUE INDEX "Pizzas_name_key" ON "Pizzas"("name");

-- CreateIndex
CREATE UNIQUE INDEX "Weapons_name_key" ON "Weapons"("name");

-- CreateIndex
CREATE UNIQUE INDEX "Turtles_name_key" ON "Turtles"("name");

-- AddForeignKey
ALTER TABLE "Turtles" ADD CONSTRAINT "Turtles_weaponId_fkey" FOREIGN KEY ("weaponId") REFERENCES "Weapons"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Turtles" ADD CONSTRAINT "Turtles_favoritePizzaId_fkey" FOREIGN KEY ("favoritePizzaId") REFERENCES "Pizzas"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
