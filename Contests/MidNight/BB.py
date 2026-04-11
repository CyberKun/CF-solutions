#!/usr/bin/env python3
"""
Key insight:
  After (n-1) 'L' moves + (n-1) 'U' moves, EVERY cursor (regardless of
  starting position) is guaranteed to be at pixel (0,0), because the
  border clamping forces col -> 0 and row -> 0.

  Then we only need a BFS from (0,0) to the nearest black pixel.

  Total moves <= (n-1) + (n-1) + BFS_distance
               <= 998 + BFS_distance   (for n=500)

  Compare to the naive snake: ~4968 moves.
"""

import sys
import os
import zipfile
from collections import deque

try:
    from PIL import Image
    import numpy as np
except ImportError:
    print("pip install pillow numpy")
    sys.exit(1)


def solve(img_path: str) -> str:
    img = Image.open(img_path).convert("L")
    pixels = np.array(img, dtype=np.uint8)
    H, W = pixels.shape

    # Black pixel: value < 128
    is_black = pixels < 128

    n = max(H, W)  # steps needed to reach corner

    # ── Step 1: normalize all cursors to (0,0) ──────────────────────────
    prefix = "L" * (W - 1) + "U" * (H - 1)

    # If (0,0) itself is black we're done right here
    if is_black[0, 0]:
        return prefix

    # ── Step 2: BFS from (0,0) to nearest black pixel ───────────────────
    DIRS = [("U", -1, 0), ("D", 1, 0), ("L", 0, -1), ("R", 0, 1)]

    dist = np.full((H, W), -1, dtype=np.int32)
    parent = [[None] * W for _ in range(H)]  # (pr, pc, move_char)
    dist[0, 0] = 0
    q = deque()
    q.append((0, 0))
    found = None

    while q and found is None:
        r, c = q.popleft()
        for move, dr, dc in DIRS:
            nr, nc = r + dr, c + dc
            if 0 <= nr < H and 0 <= nc < W and dist[nr, nc] == -1:
                dist[nr, nc] = dist[r, c] + 1
                parent[nr][nc] = (r, c, move)
                if is_black[nr, nc]:
                    found = (nr, nc)
                    break
                q.append((nr, nc))

    if found is None:
        raise RuntimeError(f"No black pixel reachable from (0,0) in {img_path}?!")

    # Reconstruct BFS path
    path = []
    r, c = found
    while parent[r][c] is not None:
        pr, pc, move = parent[r][c]
        path.append(move)
        r, c = pr, pc
    path.reverse()
    bfs_part = "".join(path)

    result = prefix + bfs_part
    return result


def main():
    # Accept optional input directory as first argument
    input_dir = sys.argv[1] if len(sys.argv) > 1 else "."
    output_dir = sys.argv[2] if len(sys.argv) > 2 else "."

    os.makedirs(output_dir, exist_ok=True)

    total_moves = 0
    found_any = False

    for i in range(1, 9):
        fname = f"{i:02d}.png"
        fpath = os.path.join(input_dir, fname)
        if not os.path.exists(fpath):
            print(f"[{fname}] not found, skipping")
            continue

        seq = solve(fpath)
        out_path = os.path.join(output_dir, f"{i:02d}.out")
        with open(out_path, "w") as f:
            f.write(seq)

        print(f"[{fname}]  length = {len(seq):>5}  "
              f"(prefix={len(seq) - len(seq.lstrip('LU')):>4}, bfs={len(seq.lstrip('LU')):>4})")
        total_moves += len(seq)
        found_any = True

    if found_any:
        print(f"\nTotal moves across all solved tests: {total_moves}")

    # Optionally pack into a zip
    zip_path = os.path.join(output_dir, "answers.zip")
    with zipfile.ZipFile(zip_path, "w") as zf:
        for i in range(1, 9):
            p = os.path.join(output_dir, f"{i:02d}.out")
            if os.path.exists(p):
                zf.write(p, arcname=f"{i:02d}.out")
    print(f"\nWrote {zip_path}")


if __name__ == "__main__":
    main()