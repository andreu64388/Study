import { v4 as uuidv4 } from 'uuid';
const validateCard=(cardNumber)=> {
    console.log('Card number:', cardNumber);
    return Math.random() < 0.5;
}

const createOrder=(cardNumber)=> {
    return new Promise((resolve, reject) => {
        if (!validateCard(cardNumber)) {
            reject(new Error('Card is not valid'));
        } else {
            const orderId = uuidv4();
            setTimeout(() => resolve(orderId), 5000);
        }
    });
}

const proceedToPayment=(orderId)=> {
    return new Promise((resolve, reject) => {
        console.log('Order ID:', orderId);
        const paymentSuccess = Math.random() < 0.5;
        if (paymentSuccess) {
            resolve('Payment successful');
        } else {
            reject(new Error('Payment failed'));
        }
    });
}


 const paymentProcess=async()=> {
    try {
        const orderId = await createOrder('5678-1234-9012-3456');
        const paymentResult = await proceedToPayment(orderId);
        console.log('Result:', paymentResult);
    } catch (error) {
        console.error('Error:', error.message);
    }
}

paymentProcess();
