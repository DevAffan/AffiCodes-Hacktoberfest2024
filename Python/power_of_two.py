

class Power:
    def __init__(self,Number):
        self.Number = Number
       
        
    def powerchecker(self):
        
        if self.Number == 1:
            return True
                
        while self.Number % 2 == 0:
            self.Number = self.Number / 2
            
            if self.Number == 1.0:
                return True
            elif self.Number % 2 != 0:
                return False
            
            

            
            
if __name__ == "__main__":
    p = Power(18)
    print(p.powerchecker())