import "./AddLot.css";
import { MdKeyboardDoubleArrowLeft } from "react-icons/md";
import Logo from "../../../assets/logo.png";
import Footer from "../../common/footer/Footer";
import { useNavigate } from "react-router";
import { useState } from "react";
import { apiConnector } from "../../../services/apiconnector";
import { parking_api } from "../../../services/apis";

const Addcar=()=>{
    const [make,setMake]=useState("");
    const [model,setModel]=useState("");
    const [reg,setReg]=useState("");
    const navigate=useNavigate();



    function regHandeler(e){
        setReg(e.target.value);
    }

    function modelhandeler(e){
        setModel(e.target.value);
    }

    function makeHandeler(e){
        setMake(e.target.value);
    }

    const username = JSON.parse(localStorage.getItem('user'));

   async function saveHandeler(){
        console.log(make);
        console.log(model);
        console.log(reg);
        var token=username?.token;
        console.log(token);
        try{
            var address =make;
            var house=model;
            var contactnumber=reg;
            const res=await apiConnector("POST",parking_api.LOTADD_API,{address,house,contactnumber,token})
            console.log(res);
            // localStorage.setItem('user', JSON.stringify(res?.data?.userDetails));
            navigate("/lotaddsucc");
        }
        catch(error){

        }
        
    }





    return(
        <div className="addcar-wraper">
        <div className="addcar-logobox">
            <MdKeyboardDoubleArrowLeft onClick={()=>navigate(-1)} className="arrow" />
            <img src={Logo} alt="Logo"/>
        </div>
        <h2 className="addcar-header">Add Lot</h2>
        <div className="addcar-input-wraper">
            <div className="addcar-input-2items">
                <p className="addcar-name">Address</p>
                <input value={make} onChange={(e)=>makeHandeler(e)} className="addcar-input" type="text" />
            </div>
            <div className="addcar-input-2items">
                <p className="addcar-name">House No.</p>
                <input value={model} onChange={(e)=>modelhandeler(e)} className="addcar-input" type="text" />
            </div>
            <div className="addcar-input-2items">
                <p className="addcar-name">Contact number</p>
                <input value={reg} onChange={(e)=>regHandeler(e)} className="addcar-input" type="text" />
            </div>
            <button onClick={saveHandeler}>Save</button>
            
        </div>
        <Footer/>
    </div>
    )
}

export default Addcar;