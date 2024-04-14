import { PrismaClient } from '@prisma/client';

const prisma = new PrismaClient();

class WeaponService {
    async getAllWeapons() {
        try {
            const weapons = await prisma.weapons.findMany();
            return weapons;
        } catch (error) {
            throw new Error('Unable to fetch weapons');
        }
    }

    async getWeaponsById(id) {
        try {
            const weapon = await prisma.weapons.findUnique({
                where: { id: parseInt(id) }
            });
            if (!weapon) {
                throw new Error('Weapon with this Id is not found');
            }
            return weapon;
        } catch (error) {
            throw new Error('Unable to find weapon');
        }
    }

    async getWeaponsByGreaterDps(n) {
        try {
            const weapons = await prisma.weapons.findMany({
                where: { dps: { gt: parseInt(n) } }
            });
            return weapons;
        } catch (error) {
            throw new Error('Unable to find weapons');
        }
    }

    async getWeaponsByLessDps(n) {
        try {
            const weapons = await prisma.weapons.findMany({
                where: { dps: { lt: parseInt(n) } }
            });
            return weapons;
        } catch (error) {
            throw new Error('Unable to find weapons');
        }
    }

    async postNewWeapon(data) {
        try {
            if(!data.name || !data.dps) throw new Error('Missing data');

            const isWeaponExist = await prisma.weapons.findUnique({
                where: { name: data.name }
            });

            if(isWeaponExist) throw new Error('Weapon already exist');

            const newWeapon = await prisma.weapons.create({
                data: { name: data.name, dps: data.dps }
            });
            return newWeapon;
        } catch (error) {
            throw new Error('Unable to create new weapon: ' + error.message);
        }
    }

    async updateWeaponById(id, newData) {
        try {

            if (!id) throw new Error('Missing weapon id');

            const weapon = await prisma.weapons.findUnique({
                where: { id: parseInt(id) }
            });
            if (!weapon) {
                throw new Error('Weapon with this Id is not found');

            }

            if (!newData.name && !newData.dps) {
                throw new Error('Missing data');
            }

            const isWeaponExist = await prisma.weapons.findUnique({
                where: { name: newData.name }
            });

            if(isWeaponExist) throw new Error('Weapon already exist');
            
            const updatedWeapon = await prisma.weapons.update({
                where: { id: parseInt(id) },
                data: newData
            });
            return updatedWeapon;
        } catch (error) {
            throw new Error('Unable to update weapon: ' + error.message);
        }
    }

    async deleteWeaponById(id) {
        try {
            if (!id) throw new Error('Missing weapon id');
            console.log(id);
            const weapon = await prisma.weapons.findUnique({
                where: { id: parseInt(id) }
            });
            if (!weapon) {
                throw new Error('Weapon with this Id is not found');
            }

            const deletedWeapon = await prisma.weapons.delete({
                where: { id: parseInt(id) }
            });
            return deletedWeapon;
        } catch (error) {
            throw new Error('Unable to delete weapon: ' + error.message);
        }
    }
}

export default new WeaponService();
