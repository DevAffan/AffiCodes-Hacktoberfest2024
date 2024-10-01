# AffiCodes - Hacktoberfest 2024 - Java

Welcome to the **Java** section of the **AffiCodes** repository! This folder contains a collection of Java programs designed to help beginners learn programming concepts through practical examples and algorithms.

## Table of Contents

- [Overview](#overview)
- [What is Java?](#what-is-java)
- [Installation Instructions](#installation-instructions)
  - [Downloading Java](#downloading-java)
  - [Installing Java on Windows](#installing-java-on-windows)
  - [Installing Java on macOS](#installing-java-on-macos)
  - [Installing Java on Linux](#installing-java-on-linux)
- [Running Java Programs](#running-java-programs)
  - [Compiling Java Programs](#compiling-java-programs)
  - [Running Java Programs](#running-java-programs-1)
- [Java Programs](#java-programs)
- [Contact](#contact)

## Overview

The Java folder contains various programming examples ranging from basic algorithms to mini-projects. Each program is intended to illustrate different programming concepts and provide hands-on experience for new learners.

## What is Java?

Java is a high-level, class-based, object-oriented programming language that is designed to have as few implementation dependencies as possible. It is widely used for building enterprise-scale applications, mobile applications (especially Android), and web applications. Java is known for its portability, meaning that once you write a Java program, you can run it on any device that has the Java Runtime Environment (JRE) installed.

## Installation Instructions

### Downloading Java

To get started with Java, you need to install the **Java Development Kit (JDK)**. You can download the latest version of JDK from the official Oracle website or use OpenJDK.

- **Oracle JDK**: [Oracle JDK Downloads](https://www.oracle.com/java/technologies/javase-jdk11-downloads.html)
- **OpenJDK**: [OpenJDK Downloads](https://openjdk.java.net/install/)

### Installing Java on Windows

1. **Download** the JDK installer from the Oracle website.
2. **Run** the installer and follow the on-screen instructions.
3. **Set the JAVA_HOME environment variable**:
   - Right-click on "This PC" or "Computer" on the desktop or File Explorer and select "Properties".
   - Click on "Advanced system settings".
   - In the System Properties window, click the "Environment Variables" button.
   - Under "System variables", click "New" and add:
     - Variable name: `JAVA_HOME`
     - Variable value: path to your JDK installation (e.g., `C:\Program Files\Java\jdk-11.x.x`)
   - Click OK to save.

### Installing Java on macOS

1. **Download** the JDK installer from the Oracle website.
2. **Open** the downloaded `.dmg` file and follow the instructions to install.
3. **Set the JAVA_HOME environment variable**:
   - Open Terminal and run the following command:
     ```bash
     echo 'export JAVA_HOME=$(/usr/libexec/java_home)' >> ~/.bash_profile
     source ~/.bash_profile
     ```

### Installing Java on Linux

1. **Open Terminal**.
2. **Update the package index**:
   ```bash
   sudo apt update
   ```
3. **Install the default JDK**:
   ```bash
   sudo apt install default-jdk
   ```
4. **Verify the installation**:
   ```bash
   java -version
   ```

## Running Java Programs

### Compiling Java Programs

To compile a Java program, you need to navigate to the directory containing your `.java` file and run the following command in your terminal:

```bash
javac <ProgramName>.java
```

**Example:**

```bash
java HelloWorld
```
