with open(r"E:\MinecraftConsoles\Minecraft.Client\Common\UI\UIScene.cpp", "r", encoding="utf-8") as f:
    content = f.read()

# Fix 1: Add fallback for blockX/blockY after parsing
old_parse = """    cfg.blockX = findValue("blockX");
    cfg.blockY = findValue("blockY");"""

new_parse = """    cfg.blockX = findValue("blockX");
    cfg.blockY = findValue("blockY");
    if (cfg.blockX == 0) cfg.blockX = cfg.x;
    if (cfg.blockY == 0) cfg.blockY = cfg.y;"""

content = content.replace(old_parse, new_parse)

# Fix 2 & 3: In Pass 3, use blockGapX/Y for scale instead of slotWidth/Height
old_scale = """            float sx = cfg.blockX + c * blockGapX;
            float sy = cfg.blockY + r3 * blockGapY;
            float scaleX = cfg.slotWidth / 16.0f;
            float scaleY = cfg.slotHeight / 16.0f;"""

new_scale = """            float sx = cfg.blockX + c * blockGapX;
            float sy = cfg.blockY + r3 * blockGapY;
            float scaleX = blockGapX / 16.0f;
            float scaleY = blockGapY / 16.0f;"""

content = content.replace(old_scale, new_scale)

with open(r"E:\MinecraftConsoles\Minecraft.Client\Common\UI\UIScene.cpp", "w", encoding="utf-8") as f:
    f.write(content)
print("Done")
