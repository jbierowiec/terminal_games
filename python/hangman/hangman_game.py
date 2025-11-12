import string

class HangmanGame:
    def __init__(self, secret: str, renderer):
        self.word = secret
        self.renderer = renderer
        self.guessed = set()
        self.wrong = set()
        self.mistakes = 0
        self.max_mistakes = renderer.max_mistakes()

    def read_letter(self):
        while True:
            try:
                s = input("Enter a letter (A-Z): ").strip().lower()
            except EOFError:
                return None
            if len(s) == 1 and s in string.ascii_lowercase:
                return s
            print("Invalid input. Please type a single letter.")

    def all_revealed(self):
        return all(c in self.guessed for c in self.word)

    def masked_word(self):
        return " ".join(c.upper() if c in self.guessed else "_" for c in self.word)

    def print_state(self):
        print("\n" + self.renderer.stage(self.mistakes))
        print(f"Word: {self.masked_word()}")
        print("Guessed:", " ".join(sorted(c.upper() for c in self.guessed)) or "(none)")
        print("Wrong:  ", " ".join(sorted(c.upper() for c in self.wrong)) or "(none)")
        print(f"Lives remaining: {self.max_mistakes - self.mistakes}")

    def run_round(self):
        print("\n========== HANGMAN ==========")
        self.print_state()

        while self.mistakes < self.max_mistakes:
            g = self.read_letter()
            if g is None:
                print("\nGoodbye!")
                return False

            if g in self.guessed or g in self.wrong:
                print(f"You already tried '{g.upper()}'. Try another.")
                continue

            if g in self.word:
                self.guessed.add(g)
                print(f"\nNice! '{g.upper()}' is in the word.\n")
            else:
                self.wrong.add(g)
                self.mistakes += 1
                print(f"\nOops! '{g.upper()}' is not in the word.\n")

            self.print_state()

            if self.all_revealed():
                print(f"You WIN! The word was: {self.word}")
                return True

        print(f"You LOSE! The word was: {self.word}")
        return True
