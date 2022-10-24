import express from "express";
import dotenv from 'dotenv';
import cors from 'cors'
import { connection } from "./connection/db.js";
import default_action from "./default.js";
import News from "./model/schema.js";

const app=express();
dotenv.config();

const username=process.env.DB_username;
const password=process.env.DB_password;

app.use(cors());

app.listen(8000,()=>{console.log('Listening to Port 8000')})

//db Connection
connection(username,password);

default_action();

app.get('/',async(req,res)=>{

    try {
      const data=  await News.find({});
      res.status(200).json(data) 
    } catch (error) {
        console.log(error)
    }

})