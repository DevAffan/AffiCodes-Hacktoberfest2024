import 'package:flutter/material.dart';

import 'package:get/get.dart';
import 'package:internet_connectivity_app/app/network/controllers/network_controller.dart';

import '../controllers/home_controller.dart';

class HomeView extends GetView<HomeController> {
  final NetworkController _networkController = Get.find<NetworkController>();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('HomeView'),
        centerTitle: true,
      ),
      body: Center(
        child: Obx(()=>Text(_networkController.connectionStatus.value==1? 'Wifi Connected!'
        :(_networkController.connectionStatus.value==2? 'Mobile Data Connected'
        :'No Connection'),
        style: TextStyle(fontSize: 20), ),
         )),
      
    );
  }
}
