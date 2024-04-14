import { Router } from "express";
import * as weaponController from "../controllers/weaponController.js";

const router = Router();

router.get('/', weaponController.getAllWeapons);
router.get('/:id', weaponController.getWeaponsById);
router.post('/', weaponController.postNewWeapon);
router.put('/:id', weaponController.updateWeaponById);
router.delete('/:id', weaponController.deleteWeaponById);

export default router;
