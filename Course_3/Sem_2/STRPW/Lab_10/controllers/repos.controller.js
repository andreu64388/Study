const ReposService = require('../services/repos.service');


class ReposController {
    async getAllRepos(req, res) {
        try {
            const repos = await ReposService.getAllRepos();
            res.json(repos);
        } catch (error) {
            throw new Error(error.message);
        }
    }
    async getRepoById(req, res) {
        const { id } = req.params;
        try {
            const repo = await ReposService.getRepoById(id);
            if (!repo) {
                res.status(404).json({ error: 'Repo not found' });
            } else {
                res.json(repo);
            }
        } catch (error) {
            res.status(500).json({ error: error.message });
        }
    }
    async createRepo(req, res) {
        const data = req.body;
        console.log(JSON.stringify(data)+"test")
        try {
            const repo = await ReposService.createRepo(data);
            res.json(repo);
        } catch (error) {
            res.status(500).json({ error: error.message });
        }
    }
    async updateRepoById(req, res) {
        const {id} = req.params;
        const newData = req.body;
        try {
            const repo = await ReposService.updateRepoById(id, newData);
            res.json(repo);

        } catch (error) {
            res.status(500).json({error: error.message});
        }
    }

    async deleteRepoById(req, res) {
        const { id } = req.params;
        try {
            const repo = await ReposService.deleteRepoById(id);
            res.json(repo);
        } catch (error) {
            res.status(500).json({ error: error.message });
        }
    }

    async getReposByIdIncludeCommits(req, res) {
        const { id } = req.params;
        try {
            const repo = await ReposService.getReposByIdIncludeCommits(id);
            if (!repo) {
                res.status(404).json({ error: 'Repo not found' });
            } else {
                res.json(repo);
            }
        } catch (error) {
            res.status(500).json({ error: error.message });
        }
    }

    async getReposByIdIncludeCommit(req, res) {
        const { id } = req.params;
        try {
            const repo = await ReposService.getReposByIdIncludeCommit(id);
            if (!repo) {
                res.status(404).json({ error: 'Repo not found' });
            } else {
                res.json(repo);
            }
        } catch (error) {
            res.status(500).json({ error: error.message });
        }
    }

    async createCommit (req, res) {
        const data = req.body;
        console.log(data)
        try {
            const commit = await ReposService.createCommit(data);
            res.json(commit);
        } catch (error) {
            res.status(500).json({ error: error.message });
        }
    }

    async updateCommitById(req, res) {
        const {id} = req.params;
        const newData = req.body;
        try {
            console.log(newData+" "+id)
            const commit = await ReposService.updateCommitById(id, newData);
            res.json(commit);
        } catch (error) {
            res.status(500).json({error: error.message});
        }

    }
    async deleteCommitById(req, res) {
        const { id } = req.params;
        try {
            const commit = await ReposService.deleteCommitById(id);
            res.json(commit);
        } catch (error) {
            res.status(500).json({ error: error.message });
        }
    }
}

module.exports = new ReposController();









