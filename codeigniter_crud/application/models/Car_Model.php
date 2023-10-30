<?php

    class Car_Model extends CI_Model{

        public function create($formArray){

            $this->db->insert('car',$formArray);
            
        }

    }


?>