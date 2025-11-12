class HangmanRenderer:
    def __init__(self):
        self.stages = [
            "  +---+\n"
            "  |   |\n"
            "      |\n"
            "      |\n"
            "      |\n"
            "      |\n"
            "=========\n",
            "  +---+\n"
            "  |   |\n"
            "  O   |\n"
            "      |\n"
            "      |\n"
            "      |\n"
            "=========\n",
            "  +---+\n"
            "  |   |\n"
            "  O   |\n"
            "  |   |\n"
            "      |\n"
            "      |\n"
            "=========\n",
            "  +---+\n"
            "  |   |\n"
            "  O   |\n"
            " /|   |\n"
            "      |\n"
            "      |\n"
            "=========\n",
            "  +---+\n"
            "  |   |\n"
            "  O   |\n"
            " /|\\  |\n"
            "      |\n"
            "      |\n"
            "=========\n",
            "  +---+\n"
            "  |   |\n"
            "  O   |\n"
            " /|\\  |\n"
            " /    |\n"
            "      |\n"
            "=========\n",
            "  +---+\n"
            "  |   |\n"
            "  O   |\n"
            " /|\\  |\n"
            " / \\  |\n"
            "      |\n"
            "=========\n",
        ]

    def stage(self, mistakes: int) -> str:
        mistakes = max(0, min(mistakes, len(self.stages) - 1))
        return self.stages[mistakes]

    def max_mistakes(self) -> int:
        return len(self.stages) - 1
