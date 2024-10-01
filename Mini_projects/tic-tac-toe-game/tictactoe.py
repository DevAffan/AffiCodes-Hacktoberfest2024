import tkinter as tk
from tkinter import messagebox
import random

class TicTacToe:
    def __init__(self, root):
        self.root = root
        self.root.title("Tic-Tac-Toe")
        self.root.geometry("400x450")
        self.root.configure(bg="white")
        self.player = "X"
        self.buttons = [[None for _ in range(3)] for _ in range(3)]
        self.vs_computer = False  # Default is two-player mode
        self.create_choice_ui()

    def create_choice_ui(self):
        """Initial screen to choose between two players or vs. computer."""
        self.choice_frame = tk.Frame(self.root, bg="white")
        self.choice_frame.pack(pady=100)

        title_label = tk.Label(self.choice_frame, text="Choose Game Mode", font=('Arial', 24, 'bold'), bg="white")
        title_label.pack(pady=20)

        # Buttons for Game Mode Selection
        two_player_button = tk.Button(self.choice_frame, text="Two Players", font=('Arial', 16), bg="#4CAF50", fg="white",
                                      width=15, command=self.start_two_player_game)
        two_player_button.pack(pady=10)

        vs_computer_button = tk.Button(self.choice_frame, text="Play Against Computer", font=('Arial', 16), bg="#2196F3", fg="white",
                                       width=15, command=self.start_vs_computer_game)
        vs_computer_button.pack(pady=10)

    def start_two_player_game(self):
        """Starts the two-player mode."""
        self.vs_computer = False
        self.start_game()

    def start_vs_computer_game(self):
        """Starts the game against the computer."""
        self.vs_computer = True
        self.start_game()

    def start_game(self):
        """Sets up the game UI."""
        self.choice_frame.destroy()  # Remove the choice screen
        self.create_ui()  # Create the actual game UI

    def create_ui(self):
        """UI setup for the Tic-Tac-Toe board."""
        # Title Label
        self.title_label = tk.Label(self.root, text="Tic-Tac-Toe", font=('Arial', 24, 'bold'), bg="white", fg="black")
        self.title_label.pack(pady=10)

        # Player Turn Label
        self.turn_label = tk.Label(self.root, text=f"Player {self.player}'s Turn", font=('Arial', 16), bg="white")
        self.turn_label.pack(pady=5)

        # Frame for the Tic-Tac-Toe grid
        self.grid_frame = tk.Frame(self.root, bg="black")
        self.grid_frame.pack(pady=20)

        # Creating 3x3 grid buttons
        for i in range(3):
            for j in range(3):
                self.buttons[i][j] = tk.Button(self.grid_frame, text="", font=('Arial', 20), width=5, height=2,
                                               command=lambda i=i, j=j: self.button_click(i, j))
                self.buttons[i][j].grid(row=i, column=j, padx=5, pady=5)

        # Reset Button
        self.reset_button = tk.Button(self.root, text="Reset", font=('Arial', 16), bg="#4CAF50", fg="white",
                                      command=self.reset_game)
        self.reset_button.pack(pady=10)

    def button_click(self, i, j):
        """Handles button click for player's turn."""
        if self.buttons[i][j]["text"] == "":
            self.buttons[i][j]["text"] = self.player
            if self.check_winner():
                messagebox.showinfo("Tic-Tac-Toe", f"Player {self.player} wins!")
                self.reset_game()
            elif self.is_draw():
                messagebox.showinfo("Tic-Tac-Toe", "It's a draw!")
                self.reset_game()
            else:
                if self.vs_computer and self.player == "X":  # If playing against the computer and it's X's turn
                    self.switch_player()
                    self.computer_move()  # Let the computer make its move
                else:
                    self.switch_player()

    def computer_move(self):
        """Computer makes a random move."""
        available_moves = [(i, j) for i in range(3) for j in range(3) if self.buttons[i][j]["text"] == ""]
        if available_moves:
            move = random.choice(available_moves)
            self.buttons[move[0]][move[1]]["text"] = "O"
            if self.check_winner():
                messagebox.showinfo("Tic-Tac-Toe", "Computer wins!")
                self.reset_game()
            elif self.is_draw():
                messagebox.showinfo("Tic-Tac-Toe", "It's a draw!")
                self.reset_game()
            else:
                self.switch_player()

    def switch_player(self):
        """Switch between X and O."""
        self.player = "O" if self.player == "X" else "X"
        self.turn_label.config(text=f"Player {self.player}'s Turn")

    def check_winner(self):
        """Check for a winner."""
        # Checking rows, columns, and diagonals for a win
        for i in range(3):
            if self.buttons[i][0]["text"] == self.buttons[i][1]["text"] == self.buttons[i][2]["text"] != "":
                return True
            if self.buttons[0][i]["text"] == self.buttons[1][i]["text"] == self.buttons[2][i]["text"] != "":
                return True
        if self.buttons[0][0]["text"] == self.buttons[1][1]["text"] == self.buttons[2][2]["text"] != "":
            return True
        if self.buttons[0][2]["text"] == self.buttons[1][1]["text"] == self.buttons[2][0]["text"] != "":
            return True
        return False

    def is_draw(self):
        """Check if the game is a draw."""
        for row in self.buttons:
            for button in row:
                if button["text"] == "":
                    return False
        return True

    def reset_game(self):
        """Reset the board and start a new game."""
        for row in self.buttons:
            for button in row:
                button.config(text="")
        self.player = "X"
        self.turn_label.config(text=f"Player {self.player}'s Turn")


# Initialize the game
if __name__ == "__main__":
    root = tk.Tk()
    game = TicTacToe(root)
    root.mainloop()
