# LCE_HOW_TO_CHANGE
Noob? Nevermind! This repo can teach you how to add anything!

(Updating, currently at chapter one, branch is unready now, please wait...)

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
  //omit hundreds of lines of code agian
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
static const int netheriteIngot_Id = 422; //ID before + 256
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
	 - Your texture must sit exactly in */
```

Draw something new (16*16 texture on grid) on items.png, replace all items.png, and see what happend!

### We need a name
This part involves hex editing `.loc` files. Don't panic. 

Chapter 2 will cover hex editing basics and the language file format. 

For now, your item will show its internal name in-game. We'll fix that soon.
