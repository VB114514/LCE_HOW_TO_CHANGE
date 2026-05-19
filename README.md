# LCE_HOW_TO_CHANGE
Noob? Nevermind! This repo can teach you how to add anything!

(Updating, currently at chapter 2, chapter 3 will coming soon)

## Before You Start
- New code in the test branch is LLM-generated based on my ideas
- Tutorials are me understanding the LLM output and explaining it back in human
- Art assets came with the original repo. I'm not ripping anything from Minecraft
- This is a modding practice repo. Not a "community edition." Just tech experiments

## Tips
The tutorials in this repository are only applicable to the test branch of this repository and are not fully compatible with other game clone. The version in this repository has a different localization loading compared to other versions (like external loading of settings.ini and .loc files).

## Chapter One: Add items

### First sight of the code
First, let's see this Item.cpp

```cpp
//omit hundreds of lines of code
Item *Item::netheriteIngot = nullptr; //item register, set Item *Item::xxx to register item xxx

void Item::staticCtor()
{
  //omit hundreds of lines of code again
  Item::netheriteIngot = (new Item(166)) //item id
    ->setBaseItemTypeAndMaterial(eBaseItemType_treasure, eMaterial_undefined) //item type, treasure and underfined
    ->setIconName(L"ingotNetherite") //texture name, texture is ingotNetherite here
    ->setDescriptionId(IDS_ITEM_NETHERITE_INGOT) //item name macro, name is IDS_ITEM_NETHERITE_INGOT here
    ->setUseDescriptionId(IDS_DESC_DIAMONDS); //item description, you don't need change it, because it's useless
}
```

Register has register too, look at this Item.h:
```h
//omit hundreds of lines of code
static Item *netheriteIngot; //define item netheriteIngot


//omit hundreds of lines of code
static const int netheriteIngot_Id = 422; //ID before + 255
```
**Copy-Paste Zone:** Paste the `Item::netheriteIngot = ...` block right below the last item in `staticCtor()`. 
Change the ID number if 166 is taken.

### Now we can see
we added an item, but...can we take it? TU19 hasen't command and command block, so we can't get it by code, we need itemGroup!

itemGroup is define in IUIScene_CreativeMenu.cpp, let's see...

```cpp
DEF(eCreativeInventory_Materials)
  //omit hundreds of lines of code
  ITEM(Item::netheriteIngot_Id) //register netheriteIngot to eCreativeInventory_Materials
```
Paste it between ITEM(Item::diamond_Id) and ITEM(Item::emerald_Id) to make it appear between Diamond and Emerald.

### Be a painter
Old textures is boring, we need a new one!

Check this PreStitchedTextureMap.cpp

```cpp
void PreStitchedTextureMap::loadUVs()
{
	if(!texturesByName.empty())
	{
		// 4J Stu - We only need to populate this once at the moment as we have hardcoded positions for each texture
		// If we ever load that dynamically, be aware that the Icon objects could currently be being used by the
		// GameRenderer::runUpdate thread
		return;
	}

	for(auto& it : texturesByName)
	{
		delete it.second;
	}
	texturesByName.clear();

	if(iconType != Icon::TYPE_TERRAIN)
	{
		float horizRatio = 1.0f/16.0f;
		float vertRatio = 1.0f/16.0f;

    //omit many lines of code
    ADD_ICON(9,		1,	L"ingotNetherite") //column 9+1, row 1+1 is ingotNetherite

	/* ADD_ICON(9, 1, L"ingotNetherite")` means:
	 - Column 10 (first number 9 + 1)
	 - Row 2 (second number 1 + 1)
	 - Your texture must sit exactly in
	*/
```

Draw something new (16*16 texture on grid) on items.png, replace all items.png with new one, change your setIconName(), and see what happend!

### We need a name
Your item has no proper name yet. It shows raw internal text in-game.

Chapter 2: Hex Editing for People Who've Never Opened a Hex Editor
- We'll open a .loc file in HxD (free, tiny, safe)
- Change a few bytes
- Give your item a name

It's copy-paste. If I can do it on a laggy laptop that crashes when I switch tabs, you can do it.

### Show your mettle #1
1. Fork the `test` branch
2. Follow Chapter 1 step by step
3. Add something
4. Submit a PR to `test` branch
5. I'll check if it's playable and merge it

Yes, you can literally add anything. That's the point.

### What if I break everything?
You will. That's normal. I broke it many times before AU1.

- Game crashes → Open an Issue, paste the error
- Texture looks weird → Check your grid coordinates (column+1, row+1)
- Item won't appear → Did you add it to `IUIScene_CreativeMenu.cpp`?

We debug in public. No shame. This repo exists because I crashed my game more times than I can count.

## Chapter 2: Simple HEX

### Sharpen your tools

Notepad can read loc （but just open） , because loc will broke after you change it, we need HxD to edit languages.loc

link here: [https://mh-nexus.de/en/downloads.php?product=HxD20]

you just need these:
* Ctrl+F Search
* Ctrl+C Copy
* Ctrl+V Paste
* Edit--insert bytes (HxD) Insert

### Before You Even Open HxD

Backup your `languages.loc`. Right now. Copy-paste it somewhere safe. You WILL mess up the first time. Everyone does. Having a backup means you can delete the broken one, rename the backup, and try again in 30 seconds instead of re-extracting everything.

### HEX Technology

First, find first 65 6E 2D 55 53, that mean en_US, The four bytes after 65 6E 2D 55 53 is langSize, it means how many bytes this language has in total, like 00 02 84 53 means en_US has 164947 bytes (HEX 28453 = DEC 164947), it's really huge, hh

Then, find 00 00 00 01 01 00 05 64 65 2D 44 45, it means en_US done and de_DE start (after en_US is de_DE, so search this can find last byte of en_US) , Insert some bytes before them, input two bytes length, it means how many bytes in this name (don't forget use calc to convert to HEX!), then input name of your item, delete useless bytes, congratulations! your item has a name now!

Find SECOND 65 6E 2D 55 53, The four bytes after them is totalStrings， it means how many names in this language, we need add one, so use calc add one and input it

#### How to find the RIGHT en-US

The first `65 6E 2D 55 53` is in the language table header — skip it.

The second one is inside the actual en-US data block — that's where `totalStrings` lives.

**Pro tip:** After the second `65 6E 2D 55 53`, you'll see `00 00 00 01 01` (version=1, isStatic=true). That's how you know you're in the right place.

Last. Change langSize, how many bytes did you add? Add that number, then, loc done!

### Add some macro

Oh! we need define macro! Check out this strings.h (Use Minecraft.Client\Windows64Media\strings.h, other strings.h is useless now!)
```h
//omit 2292 of lines of code
#define IDS_ITEM_NETHERITE_INGOT                               2287 //it means name of name #2297+1 is IDS_ITEM_NETHERITE_INGOT, if you want add, use...
```

```h
#define IDS_ITEM_XXX 2288
```

#### How to find the last number
Open `strings.h`, scroll to the bottom. Find the highest `#define IDS_` number. Add 1. That's your macro number. No guessing, no conflicts.

xxx is name of your item, tips: don't forget replace 2288 with last number + 1, see ya!

### Final round!

now, remember 
```cpp
Item::netheriteIngot = (new Item(xxx)) //your item id
    ->setBaseItemTypeAndMaterial(eBaseItemType_treasure, eMaterial_undefined) //item type
    ->setIconName(L"xxx") //texture name
    ->setDescriptionId(IDS_ITEM_NETHERITE_INGOT) //item name macro
    ->setUseDescriptionId(IDS_DESC_DIAMONDS); //item description (useless)
```
this? change IDS_ITEM_NETHERITE_INGOT to your macro, then you'll see name of your item change!

Look at these! Here's some extra thing for you!

### Golden Rule
- **Replacing text?** → 2 fields to update (length + langSize)
- **Adding new text?** → 4 fields to update (length + totalStrings + langSize + the text itself)
- Always update `langSize` LAST so the math is right.

### Quick Reference: What to Update

| You changed... | Update this | Where |
|---|---|---|
| Made text longer/shorter | 2-byte length before text | Right before the text |
| Made text longer/shorter | `langSize` (4 bytes after first `en-US`) | Language table header |
| Added a new text entry | `totalStrings` (4 bytes after second `en-US`) | Inside en-US data block |
| Added a new text entry | `langSize` (4 bytes after first `en-US`) | Language table header |
| Added a new text entry | 2-byte length + text | End of en-US block |

### Search Cheat Sheet

In HxD, press Ctrl+F. Switch to "Hex-values" tab. Paste these to jump directly:

| What you want | Search this |

|---|---|
| First `en-US` (language table) | `65 6E 2D 55 53` |
| End of en-US / start of de-DE | `00 00 00 01 01 00 05 64 65 2D 44 45` |
| Second `en-US` (data block) | Press F3 after first find |
| Your item's text (if replacing) | The text you want to change |

### Show your mettle #2
1. Open old files
2. Follow Chapter 2 step by step
3. Add a name for your item
4. Submit a PR to `test` branch
5. I'll check if it's playable and merge it

Yes, you can literally add anything. That's the point.

### What if I break everything?
Don't panic. Check:
- Did you update `langSize`? (Most common mistake)
- Did you update `totalStrings`? (If adding new text)
- Is the 2-byte length correct? (Use Windows Calculator in Programmer mode, Decimal to Hex)
- Did you insert bytes instead of overwriting? (Press Insert key, or Edit → Insert bytes)

### If You Forget Everything Else
- Text longer? → number go up.
- Text shorter? → number go down.
- New text? → number go up, add text at the end.
- Game crashes? → you forgot a number. Check the table.

You now know more about binary localization than 99% of people who play Minecraft. Go touch grass, then come back for Chapter 3: Blocks.

## Chapter 3: Blocks

### Just like items

Check this Tile.cpp, You'll see: Blocks just like items!
```cpp
const float Tile::INDESTRUCTIBLE_DESTROY_TIME = -1.0f;

//sounds
Tile::SoundType *Tile::SOUND_NORMAL = nullptr; //normal
Tile::SoundType *Tile::SOUND_WOOD = nullptr; //wood
Tile::SoundType *Tile::SOUND_GRAVEL = nullptr; //gravel
Tile::SoundType *Tile::SOUND_GRASS = nullptr; //grass
Tile::SoundType *Tile::SOUND_STONE = nullptr; //etc.
Tile::SoundType *Tile::SOUND_METAL = nullptr;
Tile::SoundType *Tile::SOUND_GLASS = nullptr;
Tile::SoundType *Tile::SOUND_CLOTH = nullptr;
Tile::SoundType *Tile::SOUND_SAND = nullptr;
Tile::SoundType *Tile::SOUND_SNOW = nullptr;
Tile::SoundType *Tile::SOUND_LADDER = nullptr;
Tile::SoundType *Tile::SOUND_ANVIL = nullptr;

//omit much code......

Tile *Tile::testBlock = nullptr; //define testBlock, just like items

//omit some code......

void Tile::staticCtor()
{
	//omit much code......
	Tile::testBlock = (new Tile(174, Material::stone))
	->setBaseItemTypeAndMaterial(Item::eBaseItemType_block, Item::eMaterial_stone) //base is normal block, material is stone, you can replace it with wood, iron, gold......
	->setDestroyTime(2.0f) //set destroy time, here's 2 seconds (hand)
	->setExplodeable(10) //set explode resistance, here's 10
	->setSoundType(Tile::SOUND_STONE) //set sound, here's stone sound
	->setIconName(L"stone") //set texture, here's stone
	->setDescriptionId(IDS_TILE_STONE) //set name, here's stone
	->setUseDescriptionId(IDS_DESC_STONE) //set description, here's stone, it's useless, so you don't need change it
	->setDrop(Tile::diamondBlock_Id, 2); //drop 2 diamond blocks, replace it with Item::yourItem_Id (replace yourItem with real name) , it will drop your items! delete this line to drop 1 of itself
}
```
#### ⚠ Drop ID Warning
`setDrop(xxx, 2)` — the first parameter is an **item** ID, not a block ID.
If your block ID is 174, the item ID is also 174. They share the same number.

`setDrop(Item::diamond_Id, 2)` — drops 2 diamonds when you break this block.
Delete the `->setDrop(...)` line to make it drop 1 of itself (AU3+ default).

.h file:
```h
//omit much code......
class Tile
{
	//omit much code......
	static const int testBlock_Id = 174; //same as ID before
	//omit much code......
	static Tile *testBlock; //define block
```

just like chapter 1, right?

#### ⚠ Block ID Limit
Block IDs max out at 255. Don't go past it or things explode.
We're working on a fix. Until then, count to 255. Carefully.

### See them again
we need itemGroup to take it, do you remember items? Forget? Nevermind!
```cpp
#include "stdafx.h"
#include "IUIScene_CreativeMenu.h"

#include "UI.h"
#include "../../Minecraft.h"
#include "../../MultiPlayerLocalPlayer.h"
#include "../../../Minecraft.World/net.minecraft.world.inventory.h"
#include "../../../Minecraft.World/net.minecraft.world.level.tile.h"
#include "../../../Minecraft.World/net.minecraft.world.level.tile.entity.h"
#include "../../../Minecraft.World/net.minecraft.world.item.h"
#include "../../../Minecraft.World/net.minecraft.world.item.enchantment.h"
#include "../../../Minecraft.World/net.minecraft.world.entity.h"
#include "../../../Minecraft.World/net.minecraft.world.entity.animal.h"
#include "../../../Minecraft.World/JavaMath.h"

// 4J JEV - Images for each tab.
IUIScene_CreativeMenu::TabSpec **IUIScene_CreativeMenu::specs = nullptr;

vector< shared_ptr<ItemInstance> > IUIScene_CreativeMenu::categoryGroups[eCreativeInventoryGroupsCount];

#define ITEM(id) list->push_back( shared_ptr<ItemInstance>(new ItemInstance(id, 1, 0)) );
#define ITEM_AUX(id, aux) list->push_back( shared_ptr<ItemInstance>(new ItemInstance(id, 1, aux)) );
#define DEF(index) list = &categoryGroups[index];

void IUIScene_CreativeMenu::staticCtor()
{
	vector< shared_ptr<ItemInstance> > *list;


	// Building Blocks
	DEF(eCreativeInventory_BuildingBlocks)
		ITEM(Tile::stone_Id)
		ITEM(Tile::grass_Id)
		ITEM(Tile::dirt_Id)
		ITEM(Tile::cobblestone_Id)
		ITEM(Tile::sand_Id)
		ITEM(Tile::sandStone_Id)
		ITEM_AUX(Tile::sandStone_Id, SandStoneTile::TYPE_SMOOTHSIDE)
		ITEM_AUX(Tile::sandStone_Id, SandStoneTile::TYPE_HEIROGLYPHS)
		ITEM(Tile::coalBlock_Id)
		ITEM(Tile::goldBlock_Id)
		ITEM(Tile::ironBlock_Id)
		ITEM(Tile::lapisBlock_Id)
		ITEM(Tile::diamondBlock_Id)
		ITEM(Tile::emeraldBlock_Id)
		ITEM_AUX(Tile::quartzBlock_Id,QuartzBlockTile::TYPE_DEFAULT)
		ITEM(Tile::coalOre_Id)
		ITEM(Tile::lapisOre_Id)
		ITEM(Tile::diamondOre_Id)
		ITEM(Tile::redStoneOre_Id)
		ITEM(Tile::ironOre_Id)
		ITEM(Tile::goldOre_Id)
		ITEM(Tile::emeraldOre_Id)
		ITEM(Tile::netherQuartz_Id)
		ITEM(Tile::unbreakable_Id)
		//add ITEM(Tile::yourBlock_Id), replace yourBlock with real name, done!
```

### Draw some blocks
Old block textures is boring too, we need a new one!

Check PreStitchedTextureMap.cpp again!
```cpp
else
	{
		float horizRatio = 1.0f/16.0f;
		float vertRatio = 1.0f/32.0f;

		ADD_ICON(0,		0,	L"grass_top")
		texturesByName[L"grass_top"]->setFlags(Icon::IS_GRASS_TOP);			// 4J added for faster determination of texture type in tesselation
		ADD_ICON(0,		1,	L"stone")
		ADD_ICON(0,		2,	L"dirt")
		ADD_ICON(0,		3,	L"grass_side")
		texturesByName[L"grass_side"]->setFlags(Icon::IS_GRASS_SIDE);		// 4J added for faster determination of texture type in tesselation
		ADD_ICON(0,		4,	L"planks_oak")
		ADD_ICON(0,		5,	L"stoneslab_side")
		ADD_ICON(0,		6,	L"stoneslab_top")
		ADD_ICON(0,		7,	L"brick") //it means column 0+1, row 7+1 is brick

		/* ADD_ICON(0, 7, L"brick")` means:
	 	- Column 1 (first number 0 + 1)
	 	- Row 8 (second number 7 + 1)
	 	- Your texture must sit exactly in
		*/
```
Draw something new (16*32 texture on grid) on terrain.png, replace all terrain.png with new one, change your setIconName(), and see what happend!

### What's your name
Same as Chapter 2, If you forget, Learn again, do it, and change your setDescriptionId()!

### Blocks vs Items
| What | Items (Ch1) | Blocks (Ch3) |
|---|---|---|
| File | Item.cpp | Tile.cpp |
| Texture file | items.png | terrain.png |
| ADD_ICON file | PreStitchedTextureMap.cpp (TYPE_TERRAIN) | PreStitchedTextureMap.cpp (else) |
| Register | `Item::xxx = (new Item(id))` | `Tile::xxx = (new Tile(id, Material::xxx))` |
| Creative menu | `ITEM(Item::xxx_Id)` | `ITEM(Tile::xxx_Id)` |
| Name | `IDS_ITEM_XXX` | `IDS_TILE_XXX` |
| Drop | `It hasn't this` | `Tile::xxx->setDrop(...)` |
| Drop default | `It hasn't thisx` drops 1 of itself | `Tile::xxx` drops 1 of itself (AU3+) |
| Crash if ID > 255? | All (id of first item is 256) | **Yes** (hard limit) |

### Show your mettle #3
1. Open old files
2. Follow Chapter 3 step by step
3. Add something
4. Submit a PR to `test` branch
5. I'll check if it's playable and merge it
