#!/usr/bin/node

const filmNumber = process.argv[2];
const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + filmNumber, async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (const character of characters) {
      const res = await new Promise((resolve, reject) => {
        request(character, (error, res, body) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(body).name);
          }
        });
      });
      console.log(res);
    }
  }
});
