/*
  Warnings:

  - You are about to drop the `Commit` table. If the table is not empty, all the data it contains will be lost.

*/
-- DropForeignKey
ALTER TABLE "Commit" DROP CONSTRAINT "Commit_repoId_fkey";

-- DropTable
DROP TABLE "Commit";

-- CreateTable
CREATE TABLE "Commits" (
    "id" SERIAL NOT NULL,
    "repoId" INTEGER NOT NULL,
    "message" TEXT NOT NULL,

    CONSTRAINT "Commits_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "Commits" ADD CONSTRAINT "Commits_repoId_fkey" FOREIGN KEY ("repoId") REFERENCES "Repos"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
