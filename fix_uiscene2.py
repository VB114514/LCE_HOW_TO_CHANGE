with open(r"E:\MinecraftConsoles\Minecraft.Client\Common\UI\UIScene.cpp", "r", encoding="utf-8") as f:
    content = f.read()

old_scale = """            float sx = cfg.blockX + c * blockGapX;
            float sy = cfg.blockY + r3 * blockGapY;
            float scaleX = blockGapX / 16.0f;
            float scaleY = blockGapY / 16.0f;"""

new_scale = """            float sx = cfg.blockX + c * blockGapX;
            float sy = cfg.blockY + r3 * blockGapY;
            float scaleX = cfg.slotWidth / 16.0f;
            float scaleY = cfg.slotHeight / 16.0f;"""

content = content.replace(old_scale, new_scale)

with open(r"E:\MinecraftConsoles\Minecraft.Client\Common\UI\UIScene.cpp", "w", encoding="utf-8") as f:
    f.write(content)
print("Done")
