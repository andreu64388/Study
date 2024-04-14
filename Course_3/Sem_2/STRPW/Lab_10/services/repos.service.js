const { PrismaClient } = require('@prisma/client');
const prisma = new PrismaClient();



class ReposService {
    async getAllRepos(){
        const repos = await prisma.repos.findMany();
        return repos;
    }

    async getRepoById(id){
        const repo = await prisma.repos.findUnique({
            where: { id: parseInt(id) }
        });
        if (!repo) {
            throw new Error('Repo with this Id is not found');
        }
        return repo;
    }

    async createRepo(data){
        try {
            if(!data.name || !data.authorId) throw new Error('Missing data');

            const isRepoExist = await prisma.repos.findMany({
                where: { name: data.name }
            });

            if(isRepoExist.length) throw new Error('Repo already exist');


            const repo = await prisma.repos.create({
                data: {
                    name: data.name,
                    authorId: parseInt(data.authorId)
                }
            });
            return repo;
        } catch (error) {
            throw new Error(error);
        }
    }

    async updateRepoById(id, newData) {
        try {

            if (!id) throw new Error('Missing repo id');

            const repo = await prisma.repos.findUnique({
                where: { id: parseInt(id) }
            });
            if (!repo) {
                throw new Error('Repo with this Id is not found');

            }

            if (!newData.name && !newData.authorId) {
                throw new Error('Missing data');
            }

            const isRepoExist = await prisma.repos.findMany({
                where: { name: newData.name }
            });

            if(isRepoExist.length) throw new Error('Repo already exist');

            const updatedRepo = await prisma.repos.update({
                where: { id: parseInt(id) },
                data: {
                    name: newData.name,
                    authorId: parseInt(newData.authorId)
                }
            });
            return updatedRepo;
        } catch (error) {
            throw new Error('Unable to update repo: ' + error.message);
        }
    }

    async deleteRepoById(id) {
        try {
            if (!id) throw new Error('Missing repo id');
            const repo = await prisma.repos.delete({
                where: { id: parseInt(id) }
            });
            return repo;
        } catch (error) {
            throw new Error('Unable to delete repo: ' + error.message);
        }
    }


    async getReposByIdIncludeCommits(id){
        return await prisma.repos.findUnique({
            where: { id: parseInt(id) },
            include: { commits: true }
        });
    }

    async getReposByIdIncludeCommit(idRepos, idCommit){
        return await prisma.repos.findUnique({
            where: { id: parseInt(idRepos) },
            include: { commits: { where: { id: parseInt(idCommit) } } }
        });
    }


    async createCommit(data){
        try {
            if(!data.message || !data.repoId) throw new Error('Missing data');

            const isCommitExist = await prisma.commits.findMany({
                where: { message: data.message }
            });

            if(isCommitExist.length) throw new Error('Commit already exist');

            const commit = await prisma.commits.create({
                data: {
                    message: data.message,
                    repoId: parseInt(data.repoId)
                }
            });
            return commit;
        } catch (error) {
            throw new Error('Unable to create commit');
        }

    }
    async updateCommitById(id, newData) {
        try {

            if (!id) throw new Error('Missing commit id');


            console.log(id)
            console.log("testtstets")
            console.log(newData)
            const commit = await prisma.commits.findUnique({
                where: { id: parseInt(id) }
            });
            if (!commit) {
                throw new Error('Commit with this Id is not found');

            }

            if (!newData.message && !newData.repoId) {
                throw new Error('Missing data');
            }

            const isCommitExist = await prisma.commits.findMany({
                where: { message: newData.message }
            });

            if(isCommitExist.length) throw new Error('Commit already exist');

            const updatedCommit = await prisma.commits.update({
                where: { id: parseInt(id) },
                data: {
                    message: newData.message,
                    repoId: parseInt(newData.repoId)
                }
            });
            return updatedCommit;
        } catch (error) {
            throw new Error('Unable to update commit: ' + error.message);
        }
    }

    deleteCommitById(id){
        try {
            if (!id) throw new Error('Missing commit id');
            const commit = prisma.commits.delete({
                where: { id: parseInt(id) }
            });
            return commit;
        } catch (error) {
            throw new Error('Unable to delete commit: ' + error.message);
        }
    }
}

module.exports = new ReposService();