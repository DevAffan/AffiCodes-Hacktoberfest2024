var Pin = 1234;
var ammount = 50000;
var trials = 3;
function authorizeUser() {
    while (trials > 0) {
        var userInput = prompt('Enter Your PIN Code');
        if (userInput === null) {
            console.log('canceled prompt');
            break;
        }
        var userPin = parseInt(userInput);
        if (!isNaN(userPin) && userPin === Pin) {
            return true;
        }
        else {
            trials--;
            console.log("Incorrect PIN. You have ".concat(trials, " trails remaining, please use correct pin."));
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
            var choice = prompt('Enter your choice (1-5):');
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
                    var newPin = prompt('Enter your new 4-digits PIN:');
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
    var minWithdrawal = 500;
    var maxWithdrawal = 25000;
    var input = prompt("Enter withdrawal amount (between ".concat(minWithdrawal, " and ").concat(maxWithdrawal, "):"));
    if (input === null) {
        console.log('Withdrawal canceled.');
        return;
    }
    var withdrawalAmount = parseInt(input);
    if (!isNaN(withdrawalAmount) && withdrawalAmount >= minWithdrawal && withdrawalAmount <= maxWithdrawal && withdrawalAmount <= ammount) {
        ammount -= withdrawalAmount;
        console.log("You have withdrawn $".concat(withdrawalAmount, ". Your new balance is ").concat(ammount));
    }
    else {
        console.log('Invalid amount or insufficient balance.');
    }
}
function balanceCheck() {
    console.log("Your balance is ".concat(ammount));
}
function transfer() {
    var maxTransferAmount = ammount;
    var recipientAccountNumber = prompt('Enter the 13-digit recipient account number:');
    if (recipientAccountNumber === null || recipientAccountNumber.length !== 13) {
        console.log('Invalid account number.');
        return;
    }
    var transferAmountInput = prompt("Enter transfer amount (between 1 and ".concat(maxTransferAmount, "):"));
    if (transferAmountInput === null) {
        console.log('Transfer canceled.');
        return;
    }
    var transferAmount = parseInt(transferAmountInput);
    if (!isNaN(transferAmount) && transferAmount >= 1 && transferAmount <= maxTransferAmount) {
        console.log("Successfully transferred ".concat(transferAmount, " to account ").concat(recipientAccountNumber));
        ammount -= transferAmount;
    }
    else {
        console.log('Invalid transfer amount.');
    }
}
function changePin(newPin) {
    if (/^\d{4}$/.test(newPin)) {
        Pin = newPin;
        console.log('Your PIN has been updated successfully.');
    }
    else {
        console.log('Invalid PIN format. Please enter a 4-digit PIN.');
    }
}
main();
