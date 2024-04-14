function f1(){
    console.log("f1");
}

function f2(){
    console.log("f2");
}

function f3(){
    console.log("f3");
}

function main(){
    console.log("main");

    setTimeout(f1, 50);
    setTimeout(f2, 30);

    new Promise((resolve, reject) => {
        resolve("I am a Promise, right after f1 and f3! Really?");
    }).then(resolve=>console.log(resolve));

    new Promise((resolve, reject) => {
        resolve("I am a Promise, right after Promise!");
    }).then(resolve=>console.log(resolve));

    f2();
}

main();