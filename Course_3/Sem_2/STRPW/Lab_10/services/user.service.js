const { PrismaClient } = require('@prisma/client');
const prisma = new PrismaClient();


class UserService {
    async getAllUsers(){
        const users = await prisma.users.findMany();
        console.log(users)
        return users;
    }
    async getUserById(id){
        const user = await prisma.users.findUnique({
            where: { id: parseInt(id) }
        });
        if (!user) {
            throw new Error('User with this Id is not found');
        }
        return user;
    }
}

module.exports = new UserService();