import json
import random

class WordList:
    def __init__(self):
        self.words = []

    def load_from_json(self, path: str) -> bool:
        try:
            with open(path, "r", encoding="utf-8") as f:
                data = json.load(f)
        except (OSError, json.JSONDecodeError):
            return False

        if not isinstance(data, list):
            return False

        valid = []
        for w in data:
            if isinstance(w, str) and w.isalpha():
                valid.append(w.lower())

        if not valid:
            return False

        self.words = valid
        return True

    def pick_random(self) -> str:
        if not self.words:
            raise ValueError("Word list is empty. Load words first.")
        return random.choice(self.words)
