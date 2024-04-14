import http from 'http'

const PORT = 3000

const app = http.createServer((req, res) => {
	if (req.method === 'GET') {
		res.writeHead(200, { 'Content-Type': 'text/html' })
		res.end(getRequestInfo(req))
	} else if (req.method === '	') {
		handlePostRequest(req, res)
	}
})

function getRequestInfo(req) {
	return `<html><body><h1>Request Info:</h1>
          <p>Method: ${req.method}</p>
          <p>URI: ${req.url}</p>
          <p>Protocol Version: </p>
          <p>Headers: ${JSON.stringify(req.headers)}</p>
          </body></html>`
}

function handlePostRequest(req, res) {
	let postData = ''

	req.on('data', chunk => {
		postData += chunk
	})

	req.on('end', () => {
		res.writeHead(200, { 'Content-Type': 'text/html' })
		res.end(`<html><body><h1>POST Data:</h1><p>${postData}</p></body></html>`)
	})
}

const main = async () => {
	try {
		await app.listen(PORT)
		console.log(`Server is running on port ${PORT}`)
	} catch (err) {
		console.log(`Error: ${err.error}`)
	}
}

main()
