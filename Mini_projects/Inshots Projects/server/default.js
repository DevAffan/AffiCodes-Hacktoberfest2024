import express from 'express';
import News from "./model/schema.js";
const app=express();
import { data } from "./data.js";
const default_action= async()=>{

    try {
        await News.insertMany(data)
        console.log('Data is inserted')
    } catch (error) {
        console.log(error);
    }
}

export default default_action;
