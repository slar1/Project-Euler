#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 30 * sizeof(char)

// Struct for a card
struct card {
  // 2, 3, 4, 5, 6, 7, 8, 9, T = 10, J = 11, Q = 11, K = 12, A = 13
  // C(lub) = 0, S(pade) = 1, H(eart) = 2, D(iamond) = 3
  int value;
  int suit;
} card;

// Struct for a hand
struct hand {
  struct card *hand;

  // Hand value
  int hand_value;

} hand1, hand2;

int equal_suits(struct hand *h) {
  for (int c = 1; c < 5; c++) {
    // Check if each card's suit is the same
    if (h->hand[c].suit != h->hand[c - 1].suit) {
      return 0;
    }
  }
  return 1;
}

int ordered(struct hand *h) {
  // If the first card and last card is a 2 and an ace, there's a possible A-5
  // straight.

  // If no ace exists
  if (h->hand[4].value != 13) {
    for (int c = 3; c >= 0; c--) {
      if (h->hand[c + 1].value - h->hand[c].value != 1) {
        return 0;
      }
    }
    return 1;
  }

  // If ace exists and 2 exists, check if cards 0 to 4 are straight. If they
  // are straight, ace becomes 1.
  if (h->hand[4].value == 13 && h->hand[0].value == 2) {
    for (int c = 2; c >= 0; c--) {
      if (h->hand[c + 1].value - h->hand[c].value != 1) {
        return 0;
      }
    }
    // Change ace to 1, update hand struct's hand, return 1.
    struct card update_ace = {1, h->hand[4].suit};
    struct card *updated_hand = malloc(5 * sizeof(struct card));
    updated_hand[0] = update_ace;

    for (int c = 1; c < 5; c++) {
      updated_hand[c] = h->hand[c];
    }
    h->hand = updated_hand;
    return 1;
  }
  return 0;
}

int full_house(struct hand *h) {
  if (h->hand[0].value == h->hand[1].value &&
      h->hand[2].value == h->hand[3].value == h->hand[4].value) {
    return 1;
  } else if (h->hand[0].value == h->hand[1].value == h->hand[2].value &&
             h->hand[3].value == h->hand[4].value) {
    return 1;
  }
  return 0;
}

int three_four(struct hand *h) {
  // Four
  for (int i = 0; i < 2; i++) {
    if (h->hand[i].value == h->hand[i + 1].value == h->hand[i + 2].value ==
        h->hand[i + 3].value) {
      return 7;
    }
  }

  // Three
  for (int i = 0; i < 3; i++) {
    if (h->hand[i].value == h->hand[i + 1].value == h->hand[i + 2].value) {
      return 3;
    }
  }

  return 0;
}

int two_double(struct hand *h) {
  int number_of_pairs = 0;

  for (int i = 0; i < 5; i++) {
    if (h->hand[i].value == h->hand[i + 1].value) {
      number_of_pairs++;
    }
  }

  if (number_of_pairs == 1) {
    return 1;
  }
  if (number_of_pairs == 2) {
    return 2;
  }

  return 0;
}

int hand_value(struct hand *h) {
  // High Card = 0, One Pair = 1, Two Pairs = 2, Three of a Kind = 3, Straight =
  // 4, Flush = 5, Full House = 6, Four of a Kind = 7, Straight Flush = 8, Royal
  // Flush = 9

  // Flushes and straights
  if (equal_suits(h) && ordered(h) && h->hand[0].value == 10) {
    return 9;
  } else if (equal_suits(h) && ordered(h)) {
    return 8;
  } else if (equal_suits(h)) {
    return 5;
  } else if (ordered(h)) {
    return 4;
  }

  // Full house
  if (full_house(h)) {
    return 6;
  }

  // Three and four of a kind
  int tf = three_four(h);
  if (tf) {
    return tf;
  }

  // Two and double
  int tb = two_double(h);
  if (tb) {
    return tb;
  }

  return 0;
}

// function that compares two hands
int compare_hands(struct hand h1, struct hand h2) {
  // First determine the hand type for h1 and h2:
  //
  // If both have the same hand determine which has the higher card within the
  // hand. If both have the same higher card within the hand, determine which
  // has the higher card outside of the hand.

  return 0;
}

int main() {
  FILE *file;
  char line_buffer[MAX_LINE_LENGTH];

  file = fopen("0054_poker.txt", "r");

  if (file == NULL) {
    printf("Error: No file.\n");
    return 1;
  }

  char ch;

  int ch_count = 1;
  int value_suit = 0;

  struct card hand1[5], hand2[5];

  // I think load it line by line, and then go from there.
  while ((ch = fgetc(file)) != EOF) {
    if (ch == ' ') {
      continue;
    }

    if (ch == 'T') {
      ch = 10;
    } else if (ch == 'J') {
      ch = 11;
    } else if (ch == 'Q') {
      ch = 12;
    } else if (ch == 'K') {
      ch = 13;
    } else if (ch == 'A') {
      ch = 14;
    } else if (ch == 'C') {
      ch = 0;
    } else if (ch == 'S') {
      ch = 1;
    } else if (ch == 'H') {
      ch = 2;
    } else if (ch == 'D') {
      ch = 3;
    } else {
      ch = ch - '0';
    }

    if (ch_count % 2 != 0) {
    }

    putchar(ch);
  }

  fclose(file);
  return 0;
}
