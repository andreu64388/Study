const thirdJob=(data)=> {
    return new Promise((resolve, reject) => {
        if (!Number.isInteger(data)) {
            reject(new Error('Ошибка: data не является числом'));
        } else {
            const isOdd = data % 2 !== 0;

            const delay = isOdd ? 1000 : 2000;

            setTimeout(() => {
                isOdd ? resolve('odd') : reject(new Error('even'));
            }, delay);
        }
    });
}


thirdJob("тест")
    .then((result) => {
        console.log('Вывод результата (Promise):', result);
    })
    .catch((error) => {
        console.error('Вывод ошибки (Promise):', error.message);
    });



const handleAsyncJob = async () => {
    try {
        const result = await thirdJob(6);
        console.log('Вывод результата (async/await):', result);
    } catch (error) {
        console.error('Вывод ошибки (async/await):', error.message);
    }
};

handleAsyncJob();
