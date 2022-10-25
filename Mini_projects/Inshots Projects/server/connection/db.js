import mongoose from "mongoose";

export const connection=(username,password)=>{
    const URL=`mongodb://${username}:${password}@anas-shard-00-00.0be97.mongodb.net:27017,anas-shard-00-01.0be97.mongodb.net:27017,anas-shard-00-02.0be97.mongodb.net:27017/user_news?ssl=true&replicaSet=atlas-37d5r8-shard-0&authSource=admin&retryWrites=true&w=majority`
    try {
        mongoose.connect(URL, {useNewUrlParser:true,useUnifiedTopology:true})
        console.log('connected to db')
    } catch (error) {
        console.log(error)
    }
}