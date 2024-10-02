import qrcode

upi_id = input("Enter your UPI ID: ")
amount = int(input("Enter amount to pay: "))

#general payment url
#upi://pay?pa=UPI_ID&pn=NAME&am=AMOUNT&cu=CURRENCY&tn=MESSAGE

url = f'upi://pay?pa={upi_id}&pn=Recipient%20Name&am={amount}'


#making qr codes
qr = qrcode.make(url)

# #saving qr codes
# phonepe_qr.save("phonepe_qr.png")
# googlepay_qr.save("googlepay_qr.png")
# paytm_qr.save("paytm_qr.png")

#show qr code
qr.show()
