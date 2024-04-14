const router = require('express').Router();
const reposRouter = require('../controllers/repos.controller');


router.get('/', reposRouter.getAllRepos);
router.get('/:id', reposRouter.getRepoById);
router.post('/', reposRouter.createRepo);
router.put('/:id', reposRouter.updateRepoById);
router.delete('/:id', reposRouter.deleteRepoById);
router.get('/:id/commits', reposRouter.getReposByIdIncludeCommits);
router.get('/:id/commits/:commitId', reposRouter.getReposByIdIncludeCommit);
router.post('/:id/commits', reposRouter.createCommit);
router.put('/commits/:id', reposRouter.updateCommitById);
router.delete('/commits/:id', reposRouter.deleteCommitById);

module.exports = router;