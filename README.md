# crkbd-keymap

Custom QMK keymap for the **Corne (crkbd) hotswap v2.0** split keyboard with Pro Micro controllers and vertically-mounted SSD1306 128x32 OLEDs.

## Animations

9 OLED animations selectable per-half via both shifts + letter key:

| # | Animation | Key (master) | Key (slave) |
|---|-----------|-------------|-------------|
| 0 | Bongo Cat | A | Z |
| 1 | Bouncing Ball | S | X |
| 2 | Sine Wave | D | C |
| 3 | Gru | F | V |
| 4 | Diego + Cat | G | B |
| 5 | Nyan Cat | H | N |
| 6 | Ocean Dream | J | M |
| 7 | Crab | K | , |
| 8 | Palm Tree | L | . |

### Highlights

- **Ocean Dream** — Moon with phase cycling (full > crescent > new > crescent > full, 1 step per 2 keystrokes), twinkling cross-shaped stars, hills/island, and flowing stream-line ocean
- **Palm Tree** — Swaying palm tree (reacts to typing), shooting stars, island, and slow-flowing ocean stream lines
- **Bongo Cat** — Classic bongo cat that taps on keypress
- **Nyan Cat** — Nyan cat with rainbow trail

## Hardware

- **Board:** crkbd rev1 (Corne hotswap v2.0)
- **MCU:** ATmega32u4 (Pro Micro), Caterina bootloader
- **Flash:** 28672 bytes available
- **OLEDs:** SSD1306 128x32, vertically mounted, `OLED_ROTATION_180`
- **Split sync:** RPC via `SPLIT_TRANSACTION_IDS_USER` — syncs animation ID and frame counter to slave half

## Building

Requires [QMK firmware](https://github.com/qmk/qmk_firmware). Copy these files into your QMK keymap directory:

```bash
cp keymap.c config.h rules.mk \
  /path/to/qmk_firmware/keyboards/crkbd/keymaps/via/
```

Compile and flash:

```bash
qmk compile -kb crkbd/rev1 -km via
avrdude -p atmega32u4 -c avr109 -P /dev/cu.usbmodem* \
  -U flash:w:crkbd_rev1_via.hex:i
```

## Files

- `keymap.c` — Keymap, animation rendering, and split sync logic
- `config.h` — Split RPC and animation frame rate defines
- `rules.mk` — Build feature flags (VIA enabled, RGB disabled)
