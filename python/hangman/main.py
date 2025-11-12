from hangman_renderer import HangmanRenderer
from hangman_game import HangmanGame
from word_list import WordList

def main():
    wl = WordList()
    if not wl.load_from_json("words.json"):
        print("Failed to load words.json (must be a JSON array of alphabetic strings).")
        return

    renderer = HangmanRenderer()

    while True:
        word = wl.pick_random()
        game = HangmanGame(word, renderer)
        finished = game.run_round()
        if not finished:
            break

        ans = input("\nPlay again? (y/n): ").strip().lower()
        if not ans or ans[0] != "y":
            break

    print("\nThanks for playing!")


if __name__ == "__main__":
    main()
