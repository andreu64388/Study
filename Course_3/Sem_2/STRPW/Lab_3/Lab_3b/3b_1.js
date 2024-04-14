const firstJob=()=> {
    return new Promise((resolve) => {
        setTimeout(() => {
            resolve("Hello World");
        }, 2000);
    });
}


firstJob().then((result) => {
    console.log(result);
}).catch((error) => {
    console.error(error);
});


 const handleFirstJob= async()=> {
    try {
        const result = await firstJob();
        console.log(result);
    } catch (error) {
        console.error(error);
    }
}

handleFirstJob();
