import 'dart:async';

import 'package:flutter/cupertino.dart';
import 'package:flutter/services.dart';
import 'package:get/get.dart';
import 'package:connectivity/connectivity.dart';

class NetworkController extends GetxController{
var connectionStatus = 0.obs;
final Connectivity _connectivity = Connectivity();
late ConnectivityResult result;
late StreamSubscription<ConnectivityResult> _streamSubscription;
@override
  void onInit() {
    super.onInit();
    initConnectivity();
    _streamSubscription = _connectivity.onConnectivityChanged.listen(_updateConnectionStatus);
  }

  Future<void> initConnectivity () async {
    
    try{
   result = await _connectivity.checkConnectivity();
    } on PlatformException catch (e){
      print(e.toString());
    }
    return _updateConnectionStatus(result);
  }

  _updateConnectionStatus(ConnectivityResult result){
  switch(result){
    case ConnectivityResult.wifi:
    connectionStatus.value =1;
    Get.snackbar('Wifi Connected', "You're connected with Wifi");
    break;
    case  ConnectivityResult.mobile:
    connectionStatus.value=2;
    Get.snackbar('Mobile Data Connected', "You're connected with Mobile Data");
    break;
    case ConnectivityResult.none:
    connectionStatus.value=0;
    Get.snackbar('No Connection', "You're not connected with Internet");
    break;
    default:
    Get.snackbar('Network Error', 'Failed to Load Network Connectoin');
  }
}


@override
  void onClose() {
    _streamSubscription.cancel();
  }

}