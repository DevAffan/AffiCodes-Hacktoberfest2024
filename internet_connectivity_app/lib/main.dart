import 'package:flutter/material.dart';

import 'package:get/get.dart';
import 'package:internet_connectivity_app/app/network/bindings/network_bindings.dart';

import 'app/routes/app_pages.dart';

void main() {
  runApp(
    GetMaterialApp(
      title: "Application",
      initialRoute: AppPages.INITIAL,
      getPages: AppPages.routes,
      initialBinding: NetworkBindings(),
      debugShowCheckedModeBanner: false,
      theme: ThemeData.dark(),
    ),
  );
}
