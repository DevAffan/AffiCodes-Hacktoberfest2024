let Pin:number = 1234;
let ammount:number = 50000;
let trials:number = 3;

function authorizeUser() {
  while (trials > 0) {
    const userInput = prompt('Enter Your PIN Code');
    if (userInput === null) {
      console.log('canceled prompt');
      break;
    }
    const userPin = parseInt(userInput);
    if (!isNaN(userPin) && userPin === Pin) {
      return true;
    } else {
        trials--;
      console.log(`Incorrect PIN. You have ${trials} trails remaining, please use correct pin.`);
    }
  }

  console.log('You have exceeded the maximum number of trials. The application closed.');
  return false;
}

function displayMenu() {
  console.log('Select an option from the menu:\n');
  console.log('1: Withdraw');
  console.log('2: Balance Check');
  console.log('3: Transfer');
  console.log('4: Change PIN');
  console.log('5: Exit');
}

function main() {
  if (authorizeUser()) {
    while (true) {
      displayMenu();
      const choice = prompt('Enter your choice (1-5):');

      switch (choice) {
        case '1':
          withdraw();
          break;

        case '2':
          balanceCheck();
          break;

        case '3':
          transfer();
          break;

        case '4':
          const newPin = prompt('Enter your new 4-digits PIN:');
          changePin(newPin);
          break;

        case '5':
          console.log('Exit the application.');
          return;

        default:
          console.log('Invalid choice. Please select a valid options from (1-5).');
          break;
      }
    }
  }
}

function withdraw() {
  const minWithdrawal = 500;
  const maxWithdrawal = 25000;
  const input = prompt(`Enter withdrawal amount (between ${minWithdrawal} and ${maxWithdrawal}):`);

  if (input === null) {
    console.log('Withdrawal canceled.');
    return;
  }

  const withdrawalAmount = parseInt(input);

  if (!isNaN(withdrawalAmount) && withdrawalAmount >= minWithdrawal && withdrawalAmount <= maxWithdrawal && withdrawalAmount <= ammount) {
    ammount -= withdrawalAmount;
    console.log(`You have withdrawn $${withdrawalAmount}. Your new balance is ${ammount}`);
  } else {
    console.log('Invalid amount or insufficient balance.');
  }
}

function balanceCheck() {
  console.log(`Your balance is ${ammount}`);
}

function transfer() {
  const maxTransferAmount = ammount;
  const recipientAccountNumber = prompt('Enter the 13-digit recipient account number:');

  if (recipientAccountNumber === null || recipientAccountNumber.length !== 13) {
    console.log('Invalid account number.');
    return;
  }

  const transferAmountInput = prompt(`Enter transfer amount (between 1 and ${maxTransferAmount}):`);

  if (transferAmountInput === null) {
    console.log('Transfer canceled.');
    return;
  }

  const transferAmount = parseInt(transferAmountInput);

  if (!isNaN(transferAmount) && transferAmount >= 1 && transferAmount <= maxTransferAmount) {
    console.log(`Successfully transferred ${transferAmount} to account ${recipientAccountNumber}`);
    ammount -= transferAmount;
  } else {
    console.log('Invalid transfer amount.');
  }
}

function changePin(newPin) {
  if (/^\d{4}$/.test(newPin)) {
    Pin = newPin;
    console.log('Your PIN has been updated successfully.');
  } else {
    console.log('Invalid PIN format. Please enter a 4-digit PIN.');
  }
}

main();
