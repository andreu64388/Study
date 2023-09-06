const button = document.getElementById("rand");
const hash = document.getElementById("hash");
const hashMessage = document.getElementById("hashMessage");
const codeMessage = document.getElementById("codeMessage");
const encode = document.getElementById("encode");
const decode = document.getElementById("decode");
const pack = document.getElementById("pack");
const signa = document.getElementById("signa");

button.addEventListener("click", () => {
  const array = new Uint8Array(1);
  console.log(crypto.getRandomValues(array)[0]);
});

async function digestMessage(message) {
  const encoder = new TextEncoder(); // TextEncoder это встроенный объект, который позволяет кодировать строку в байтовый массив.
  const data = encoder.encode(message);
  const hash = await crypto.subtle.digest("SHA-256", data); // crypto.subtle.digest() возвращает Promise, который разрешается ArrayBuffer, содержащий хэш-значение.
  return hash;
}
hash.addEventListener("click", () => {
  digestMessage(hashMessage.value).then((digestBuffer) =>
    console.log(digestBuffer)
  );
  hashMessage.value = "";
});

const algoIdentifier = "AES-CBC";
let decryptKey;
let decryptKeyParams = {
  name: algoIdentifier,
  length: 256,
};
let byteMessage;
const encryptDecryptParams = {
  name: algoIdentifier,
  iv: crypto.getRandomValues(new Uint8Array(16)),
};
async function encodeMessage() {
  let key = await window.crypto.subtle.generateKey(decryptKeyParams, true, [
    "encrypt",
    "decrypt",
  ]);
  decryptKey = key;
  const originalPlaintext = new TextEncoder().encode(codeMessage.value);
  const ciphertext = await crypto.subtle.encrypt(
    encryptDecryptParams,
    key,
    originalPlaintext
  );
  byteMessage = ciphertext;
  console.log(ciphertext);
}
encode.addEventListener("click", encodeMessage);
async function decodeMessage() {
  const decryptedPlaintext = await crypto.subtle.decrypt(
    encryptDecryptParams,
    decryptKey,
    byteMessage
  );
  console.log(new TextDecoder().decode(decryptedPlaintext));
}
decode.addEventListener("click", decodeMessage);

async function WrapKey() {
  // функция для упаковки ключа
  const keyFormat = "raw";
  const extractable = true;
  const wrappingKeyAlgoIdentifier = "AES-KW";
  const wrappingKeyUsages = ["wrapKey", "unwrapKey"];
  const wrappingKeyParams = {
    name: wrappingKeyAlgoIdentifier,
    length: 256,
  };
  const wrappingKey = await crypto.subtle.generateKey(
    // генерируем ключ для упаковки
    wrappingKeyParams,
    extractable,
    wrappingKeyUsages
  );
  console.log(wrappingKey);
  const wrappedKey = await crypto.subtle.wrapKey(
    keyFormat,
    decryptKey,
    wrappingKey,
    wrappingKeyAlgoIdentifier
  );
  console.log(wrappedKey);
  const unwrappedKey = await crypto.subtle.unwrapKey(
    keyFormat,
    wrappedKey,
    wrappingKey,
    wrappingKeyParams,
    decryptKeyParams,
    extractable,
    ["encrypt", "decrypt"]
  );
  console.log(unwrappedKey);
}
pack.addEventListener("click", WrapKey);

let sign = async function () {
  // функция для подписи сообщения
  const keyParams = {
    name: "ECDSA",
    namedCurve: "P-256",
  };
  const keyUsages = ["sign", "verify"];
  const { publicKey, privateKey } = await crypto.subtle.generateKey(
    keyParams,
    true,
    keyUsages
  );
  const message = new TextEncoder().encode("Mes to sign");
  const signParams = {
    name: "ECDSA",
    hash: "SHA-256",
  };
  const signature = await crypto.subtle.sign(signParams, privateKey, message);
  const verified = await crypto.subtle.verify(
    signParams,
    publicKey,
    signature,
    message
  );
  console.log(signParams, publicKey, message);
  console.log(verified);
};
signa.addEventListener("click", () => {
  sign();
});
