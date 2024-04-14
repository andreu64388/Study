import nodemailer from 'nodemailer';

const pass = 'plmp muqj ydze rtkk';
const send = (from, to, pass, message) => {
    let transporter = nodemailer.createTransport({
        service: 'gmail',
        port: 587,
        secure: false,
        auth: {
            user: from,
            pass: pass
        }
    });

    const mailOptions = {
        from: from,
        to: to,
        subject: 'Lab5',
        text: message,
        html: `<i>${message}</i>`
    };

    transporter.sendMail(mailOptions, (error, info) => {
        if (error) {
            console.error(error);
        } else {
            console.log('Email sent: ' + info.response);
        }
    });
};

export { send };
