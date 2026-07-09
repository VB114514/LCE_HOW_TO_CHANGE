#include "stdafx.h"

#include "net.minecraft.locale.h"
#include "net.minecraft.world.h"
#include "net.minecraft.world.entity.h"
#include "net.minecraft.world.entity.item.h"
#include "net.minecraft.world.level.h"
#include "net.minecraft.world.level.tile.h"
#include "net.minecraft.world.item.h"
#include "net.minecraft.world.item.alchemy.h"
#include "net.minecraft.world.food.h"
#include "net.minecraft.world.effect.h"
#include "net.minecraft.stats.h"
#include "MapItem.h"
#include "Item.h"
#include "HangingEntityItem.h"
#include "HtmlString.h"


typedef Item::Tier _Tier;

//const UUID Item::BASE_ATTACK_DAMAGE_UUID = UUID::fromString(L"CB3F55D3-645C-4F38-A497-9C13A33DB5CF");

wstring Item::ICON_DESCRIPTION_PREFIX = L"item.";

const _Tier *_Tier::WOOD = new _Tier(0, 59, 2, 0, 15); //
const _Tier *_Tier::STONE = new _Tier(1, 131, 4, 1, 5); //
const _Tier *_Tier::IRON = new _Tier(2, 250, 6, 2, 14); //
const _Tier *_Tier::DIAMOND = new _Tier(3, 1561, 8, 3, 10); //
const _Tier *_Tier::GOLD = new _Tier(0, 32, 12, 0, 22);

Random *Item::random = new Random();

ItemArray Item::items = ItemArray( ITEM_NUM_COUNT );

Item *Item::shovel_iron = nullptr;
Item *Item::pickAxe_iron = nullptr;
Item *Item::hatchet_iron = nullptr;
Item *Item::flintAndSteel = nullptr;
Item *Item::apple = nullptr;
BowItem *Item::bow = nullptr;
Item *Item::arrow = nullptr;
Item *Item::coal = nullptr;
Item *Item::diamond = nullptr;
Item *Item::ironIngot = nullptr;
Item *Item::goldIngot = nullptr;
Item *Item::sword_iron = nullptr;

Item *Item::sword_wood = nullptr;
Item *Item::shovel_wood = nullptr;
Item *Item::pickAxe_wood = nullptr;
Item *Item::hatchet_wood = nullptr;

Item *Item::sword_stone = nullptr;
Item *Item::shovel_stone = nullptr;
Item *Item::pickAxe_stone = nullptr;
Item *Item::hatchet_stone = nullptr;

Item *Item::sword_diamond = nullptr;
Item *Item::shovel_diamond = nullptr;
Item *Item::pickAxe_diamond = nullptr;
Item *Item::hatchet_diamond = nullptr;

Item *Item::stick = nullptr;
Item *Item::bowl = nullptr;
Item *Item::mushroomStew = nullptr;

Item *Item::sword_gold = nullptr;
Item *Item::shovel_gold = nullptr;
Item *Item::pickAxe_gold = nullptr;
Item *Item::hatchet_gold = nullptr;

Item *Item::string = nullptr;
Item *Item::feather = nullptr;
Item *Item::gunpowder = nullptr;

Item *Item::hoe_wood = nullptr;
Item *Item::hoe_stone = nullptr;
Item *Item::hoe_iron = nullptr;
Item *Item::hoe_diamond = nullptr;
Item *Item::hoe_gold = nullptr;

Item *Item::seeds_wheat = nullptr;
Item *Item::wheat = nullptr;
Item *Item::bread = nullptr;

ArmorItem *Item::helmet_leather = nullptr;
ArmorItem *Item::chestplate_leather = nullptr;
ArmorItem *Item::leggings_leather = nullptr;
ArmorItem *Item::boots_leather = nullptr;

ArmorItem *Item::helmet_chain = nullptr;
ArmorItem *Item::chestplate_chain = nullptr;
ArmorItem *Item::leggings_chain = nullptr;
ArmorItem *Item::boots_chain = nullptr;

ArmorItem *Item::helmet_iron = nullptr;
ArmorItem *Item::chestplate_iron = nullptr;
ArmorItem *Item::leggings_iron = nullptr;
ArmorItem *Item::boots_iron = nullptr;

ArmorItem *Item::helmet_diamond = nullptr;
ArmorItem *Item::chestplate_diamond = nullptr;
ArmorItem *Item::leggings_diamond = nullptr;
ArmorItem *Item::boots_diamond = nullptr;

ArmorItem *Item::helmet_gold = nullptr;
ArmorItem *Item::chestplate_gold = nullptr;
ArmorItem *Item::leggings_gold = nullptr;
ArmorItem *Item::boots_gold = nullptr;

Item *Item::flint = nullptr;
Item *Item::porkChop_raw = nullptr;
Item *Item::porkChop_cooked = nullptr;
Item *Item::painting = nullptr;

Item *Item::apple_gold = nullptr;

Item *Item::sign = nullptr;
Item *Item::door_wood = nullptr;

Item *Item::bucket_empty = nullptr;
Item *Item::bucket_water = nullptr;
Item *Item::bucket_lava = nullptr;

Item *Item::minecart = nullptr;
Item *Item::saddle = nullptr;
Item *Item::door_iron = nullptr;
Item *Item::redStone = nullptr;
Item *Item::snowBall = nullptr;

Item *Item::boat = nullptr;

Item *Item::leather = nullptr;
Item *Item::bucket_milk = nullptr;
Item *Item::brick = nullptr;
Item *Item::clay = nullptr;
Item *Item::reeds = nullptr;
Item *Item::paper = nullptr;
Item *Item::book = nullptr;
Item *Item::slimeBall = nullptr;
Item *Item::minecart_chest = nullptr;
Item *Item::minecart_furnace = nullptr;
Item *Item::egg = nullptr;
Item *Item::compass = nullptr;
FishingRodItem *Item::fishingRod = nullptr;
Item *Item::clock = nullptr;
Item *Item::yellowDust = nullptr;
Item *Item::fish_raw = nullptr;
Item *Item::fish_cooked = nullptr;

Item *Item::dye_powder = nullptr;
Item *Item::bone = nullptr;
Item *Item::sugar = nullptr;
Item *Item::cake = nullptr;

Item *Item::bed = nullptr;

Item *Item::repeater = nullptr;
Item *Item::cookie = nullptr;

MapItem *Item::map = nullptr;

Item *Item::record_01 = nullptr;
Item *Item::record_02 = nullptr;
Item *Item::record_03 = nullptr;
Item *Item::record_04 = nullptr;
Item *Item::record_05 = nullptr;
Item *Item::record_06 = nullptr;
Item *Item::record_07 = nullptr;
Item *Item::record_08 = nullptr;
Item *Item::record_09 = nullptr;
Item *Item::record_10 = nullptr;
Item *Item::record_11 = nullptr;
Item *Item::record_12 = nullptr;

ShearsItem *Item::shears = nullptr;

Item *Item::melon = nullptr;

Item *Item::seeds_pumpkin = nullptr;
Item *Item::seeds_melon = nullptr;

Item *Item::beef_raw = nullptr;
Item *Item::beef_cooked = nullptr;
Item *Item::chicken_raw = nullptr;
Item *Item::chicken_cooked = nullptr;
Item *Item::rotten_flesh = nullptr;

Item *Item::enderPearl = nullptr;

Item *Item::blazeRod = nullptr;
Item *Item::ghastTear = nullptr;
Item *Item::goldNugget = nullptr;
Item *Item::netherwart_seeds = nullptr;
PotionItem *Item::potion = nullptr;
Item *Item::glassBottle = nullptr;
Item *Item::spiderEye = nullptr;
Item *Item::fermentedSpiderEye = nullptr;
Item *Item::blazePowder = nullptr;
Item *Item::magmaCream = nullptr;
Item *Item::brewingStand = nullptr;
Item *Item::cauldron = nullptr;
Item *Item::eyeOfEnder = nullptr;
Item *Item::speckledMelon = nullptr;

Item *Item::spawnEgg = nullptr;

Item *Item::expBottle = nullptr;

// TU9
Item *Item::fireball = nullptr;
Item *Item::frame = nullptr;

Item *Item::skull = nullptr;


// TU14
//Item *Item::writingBook = nullptr;
//Item *Item::writtenBook = nullptr;

Item *Item::emerald = nullptr;

Item *Item::flowerPot = nullptr;

Item *Item::carrots = nullptr;
Item *Item::potato = nullptr;
Item *Item::potatoBaked = nullptr;
Item *Item::potatoPoisonous = nullptr;

EmptyMapItem *Item::emptyMap = nullptr;

Item *Item::carrotGolden = nullptr;

Item *Item::carrotOnAStick = nullptr;
Item *Item::netherStar = nullptr;
Item *Item::pumpkinPie = nullptr;
Item *Item::fireworks = nullptr;
Item *Item::fireworksCharge = nullptr;

EnchantedBookItem *Item::enchantedBook = nullptr;

Item *Item::comparator = nullptr;
Item *Item::netherbrick = nullptr;
Item *Item::netherQuartz = nullptr;
Item *Item::minecart_tnt = nullptr;
Item *Item::minecart_hopper = nullptr;

Item *Item::horseArmorMetal = nullptr;
Item *Item::horseArmorGold = nullptr;
Item *Item::horseArmorDiamond = nullptr;
Item *Item::lead = nullptr;
Item *Item::nameTag = nullptr;

//mod items by vb
Item *Item::netheriteIngot = nullptr;

//itemSID
std::unordered_map<int, wstring> itemSID;

void Item::staticCtor()
{
	itemSID[1] = L"stone";
    itemSID[2] = L"grass";
	itemSID[3] = L"dirt";
	itemSID[4] = L"cobblestone";
	itemSID[5] = L"wood";
	itemSID[6] = L"sapling";
	itemSID[7] = L"bedrock";
	itemSID[8] = L"water";
	itemSID[9] = L"calm_water";
	itemSID[10] = L"lava";
	itemSID[11] = L"calm_lava";
	itemSID[12] = L"sand";
	itemSID[13] = L"gravel";
	itemSID[14] = L"gold_ore";
	itemSID[15] = L"iron_ore";
	itemSID[16] = L"coal_ore";
	itemSID[17] = L"tree_trunk";
	itemSID[18] = L"leaves";
	itemSID[19] = L"sponge";
	itemSID[20] = L"glass";
	itemSID[21] = L"lapis_ore";
	itemSID[22] = L"lapis_block";
	itemSID[23] = L"dispenser";
	itemSID[24] = L"sandstone";
	itemSID[25] = L"noteblock";
	itemSID[26] = L"bed";
	itemSID[27] = L"golden_rail";
	itemSID[28] = L"detector_rail";
	itemSID[29] = L"piston_sticky_base";
	itemSID[30] = L"web";
	itemSID[31] = L"tallgrass";
	itemSID[32] = L"dead_bush";
	itemSID[33] = L"piston_base";
	itemSID[34] = L"piston_extension";
	itemSID[35] = L"wool";
	itemSID[36] = L"piston_moving_piece";
	itemSID[37] = L"flower";
	itemSID[38] = L"rose";
	itemSID[39] = L"mushroom_brown";
	itemSID[40] = L"mushroom_red";
	itemSID[41] = L"gold_block";
	itemSID[42] = L"iron_block";
	itemSID[43] = L"stone_slab";
	itemSID[44] = L"stone_slab_half";
	itemSID[45] = L"red_brick";
	itemSID[46] = L"tnt";
	itemSID[47] = L"bookshelf";
	itemSID[48] = L"mossy_cobblestone";
	itemSID[49] = L"obsidian";
	itemSID[50] = L"torch";
	itemSID[51] = L"fire";
	itemSID[52] = L"mob_spawner";
	itemSID[53] = L"stairs_wood";
	itemSID[54] = L"chest";
	itemSID[55] = L"redstone_dust";
	itemSID[56] = L"diamond_ore";
	itemSID[57] = L"diamond_block";
	itemSID[58] = L"workbench";
	itemSID[59] = L"wheat";
	itemSID[60] = L"farmland";
	itemSID[61] = L"furnace";
	itemSID[62] = L"furnace_lit";
	itemSID[63] = L"sign";
	itemSID[64] = L"door_wood";
	itemSID[65] = L"ladder";
	itemSID[66] = L"rail";
	itemSID[67] = L"stairs_stone";
	itemSID[68] = L"wall_sign";
	itemSID[69] = L"lever";
	itemSID[70] = L"pressure_plate_stone";
	itemSID[71] = L"door_iron";
	itemSID[72] = L"pressure_plate_wood";
	itemSID[73] = L"redstone_ore";
	itemSID[74] = L"redstone_ore_lit";
	itemSID[75] = L"redstone_torch_off";
	itemSID[76] = L"redstone_torch_on";
	itemSID[77] = L"button_stone";
	itemSID[78] = L"top_snow";
	itemSID[79] = L"ice";
	itemSID[80] = L"snow";
	itemSID[81] = L"cactus";
	itemSID[82] = L"clay";
	itemSID[83] = L"reeds";
	itemSID[84] = L"jukebox";
	itemSID[85] = L"fence";
	itemSID[86] = L"pumpkin";
	itemSID[87] = L"nether_rack";
	itemSID[88] = L"soul_sand";
	itemSID[89] = L"glowstone";
	itemSID[90] = L"portal";
	itemSID[91] = L"lit_pumpkin";
	itemSID[92] = L"cake";
	itemSID[93] = L"diode_off";
	itemSID[94] = L"diode_on";
	itemSID[95] = L"stained_glass";
	itemSID[96] = L"trapdoor";
	itemSID[97] = L"monster_egg";
	itemSID[98] = L"stone_brick";
	itemSID[99] = L"huge_mushroom_brown";
	itemSID[100] = L"huge_mushroom_red";
	itemSID[101] = L"iron_fence";
	itemSID[102] = L"thin_glass";
	itemSID[103] = L"melon";
	itemSID[104] = L"pumpkin_stem";
	itemSID[105] = L"melon_stem";
	itemSID[106] = L"vine";
	itemSID[107] = L"fence_gate";
	itemSID[108] = L"stairs_bricks";
	itemSID[109] = L"stairs_stone_brick";
	itemSID[110] = L"mycel";
	itemSID[111] = L"waterlily";
	itemSID[112] = L"nether_brick";
	itemSID[113] = L"nether_fence";
	itemSID[114] = L"stairs_nether_bricks";
	itemSID[115] = L"nether_stalk";
	itemSID[116] = L"enchanting_table";
	itemSID[117] = L"brewing_stand";
	itemSID[118] = L"cauldron";
	itemSID[119] = L"end_portal";
	itemSID[120] = L"end_portal_frame";
	itemSID[121] = L"end_stone";
	itemSID[122] = L"dragon_egg";
	itemSID[123] = L"redstone_light";
	itemSID[124] = L"redstone_light_lit";
	itemSID[125] = L"wooden_slab";
	itemSID[126] = L"wooden_slab_half";
	itemSID[127] = L"cocoa";
	itemSID[128] = L"stairs_sandstone";
	itemSID[129] = L"emerald_ore";
	itemSID[130] = L"ender_chest";
	itemSID[131] = L"tripwire_source";
	itemSID[132] = L"tripwire";
	itemSID[133] = L"emerald_block";
	itemSID[134] = L"stairs_sprucewood";
	itemSID[135] = L"stairs_birchwood";
	itemSID[136] = L"stairs_junglewood";
	itemSID[137] = L"command_block";
	itemSID[138] = L"beacon";
	itemSID[139] = L"cobble_wall";
	itemSID[140] = L"flower_pot";
	itemSID[141] = L"carrots";
	itemSID[142] = L"potatoes";
	itemSID[143] = L"button_wood";
	itemSID[144] = L"skull";
	itemSID[145] = L"anvil";
	itemSID[146] = L"trapped_chest";
	itemSID[147] = L"weighted_pressure_plate_light";
	itemSID[148] = L"weighted_pressure_plate_heavy";
	itemSID[149] = L"comparator_off";
	itemSID[150] = L"comparator_on";
	itemSID[151] = L"daylight_detector";
	itemSID[152] = L"redstone_block";
	itemSID[153] = L"nether_quartz_ore";
	itemSID[154] = L"hopper";
	itemSID[155] = L"quartz_block";
	itemSID[156] = L"stairs_quartz";
	itemSID[157] = L"activator_rail";
	itemSID[158] = L"dropper";
	itemSID[159] = L"clay_hardened_colored";
	itemSID[160] = L"stained_glass_pane";
	itemSID[170] = L"hay_block";
	itemSID[171] = L"wool_carpet";
	itemSID[172] = L"clay_hardened";
	itemSID[173] = L"coal_block";
	itemSID[174] = L"test_block";
	itemSID[256] = L"shovel_iron";
	itemSID[257] = L"pickaxe_iron";
	itemSID[258] = L"hatchet_iron";
	itemSID[259] = L"flint_and_steel";
	itemSID[260] = L"apple";
	itemSID[261] = L"bow";
	itemSID[262] = L"arrow";
	itemSID[263] = L"coal";
	itemSID[264] = L"diamond";
	itemSID[265] = L"iron_ingot";
	itemSID[266] = L"gold_ingot";
	itemSID[267] = L"sword_iron";
	itemSID[268] = L"sword_wood";
	itemSID[269] = L"shovel_wood";
	itemSID[270] = L"pickaxe_wood";
	itemSID[271] = L"hatchet_wood";
	itemSID[272] = L"sword_stone";
	itemSID[273] = L"shovel_stone";
	itemSID[274] = L"pickaxe_stone";
	itemSID[275] = L"hatchet_stone";
	itemSID[276] = L"sword_diamond";
	itemSID[277] = L"shovel_diamond";
	itemSID[278] = L"pickaxe_diamond";
	itemSID[279] = L"hatchet_diamond";
	itemSID[280] = L"stick";
	itemSID[281] = L"bowl";
	itemSID[282] = L"mushroom_stew";
	itemSID[283] = L"sword_gold";
	itemSID[284] = L"shovel_gold";
	itemSID[285] = L"pickaxe_gold";
	itemSID[286] = L"hatchet_gold";
	itemSID[287] = L"string";
	itemSID[288] = L"feather";
	itemSID[289] = L"gunpowder";
	itemSID[290] = L"hoe_wood";
	itemSID[291] = L"hoe_stone";
	itemSID[292] = L"hoe_iron";
	itemSID[293] = L"hoe_diamond";
	itemSID[294] = L"hoe_gold";
	itemSID[295] = L"seeds_wheat";
	itemSID[296] = L"wheat";
	itemSID[297] = L"bread";
	itemSID[298] = L"helmet_leather";
	itemSID[299] = L"chestplate_leather";
	itemSID[300] = L"leggings_leather";
	itemSID[301] = L"boots_leather";
	itemSID[302] = L"helmet_chain";
	itemSID[303] = L"chestplate_chain";
	itemSID[304] = L"leggings_chain";
	itemSID[305] = L"boots_chain";
	itemSID[306] = L"helmet_iron";
	itemSID[307] = L"chestplate_iron";
	itemSID[308] = L"leggings_iron";
	itemSID[309] = L"boots_iron";
	itemSID[310] = L"helmet_diamond";
	itemSID[311] = L"chestplate_diamond";
	itemSID[312] = L"leggings_diamond";
	itemSID[313] = L"boots_diamond";
	itemSID[314] = L"helmet_gold";
	itemSID[315] = L"chestplate_gold";
	itemSID[316] = L"leggings_gold";
	itemSID[317] = L"boots_gold";
	itemSID[318] = L"flint";
	itemSID[319] = L"porkchop_raw";
	itemSID[320] = L"porkchop_cooked";
	itemSID[321] = L"painting";
	itemSID[322] = L"apple_gold";
	itemSID[323] = L"sign";
	itemSID[324] = L"door_wood";
	itemSID[325] = L"bucket_empty";
	itemSID[326] = L"bucket_water";
	itemSID[327] = L"bucket_lava";
	itemSID[328] = L"minecart";
	itemSID[329] = L"saddle";
	itemSID[330] = L"door_iron";
	itemSID[331] = L"redstone";
	itemSID[332] = L"snowball";
	itemSID[333] = L"boat";
	itemSID[334] = L"leather";
	itemSID[335] = L"bucket_milk";
	itemSID[336] = L"brick";
	itemSID[337] = L"clay";
	itemSID[338] = L"reeds";
	itemSID[339] = L"paper";
	itemSID[340] = L"book";
	itemSID[341] = L"slime_ball";
	itemSID[342] = L"minecart_chest";
	itemSID[343] = L"minecart_furnace";
	itemSID[344] = L"egg";
	itemSID[345] = L"compass";
	itemSID[346] = L"fishing_rod";
	itemSID[347] = L"clock";
	itemSID[348] = L"yellow_dust";
	itemSID[349] = L"fish_raw";
	itemSID[350] = L"fish_cooked";
	itemSID[351] = L"dye_powder";
	itemSID[352] = L"bone";
	itemSID[353] = L"sugar";
	itemSID[354] = L"cake";
	itemSID[355] = L"bed";
	itemSID[356] = L"repeater";
	itemSID[357] = L"cookie";
	itemSID[358] = L"map";
	itemSID[359] = L"shears";
	itemSID[360] = L"melon";
	itemSID[361] = L"seeds_pumpkin";
	itemSID[362] = L"seeds_melon";
	itemSID[363] = L"beef_raw";
	itemSID[364] = L"beef_cooked";
	itemSID[365] = L"chicken_raw";
	itemSID[366] = L"chicken_cooked";
	itemSID[367] = L"rotten_flesh";
	itemSID[368] = L"ender_pearl";
	itemSID[369] = L"blaze_rod";
	itemSID[370] = L"ghast_tear";
	itemSID[371] = L"gold_nugget";
	itemSID[372] = L"netherwart_seeds";
	itemSID[373] = L"potion";
	itemSID[374] = L"glass_bottle";
	itemSID[375] = L"spider_eye";
	itemSID[376] = L"fermented_spider_eye";
	itemSID[377] = L"blaze_powder";
	itemSID[378] = L"magma_cream";
	itemSID[379] = L"brewing_stand";
	itemSID[380] = L"cauldron";
	itemSID[381] = L"eye_of_ender";
	itemSID[382] = L"speckled_melon";
	itemSID[383] = L"spawn_egg";
	itemSID[384] = L"exp_bottle";
	itemSID[397] = L"skull";
	// itemSID.push_back(L"record_01");
	// itemSID.push_back(L"record_02");
	// itemSID.push_back(L"record_03");
	// itemSID.push_back(L"record_04");
	// itemSID.push_back(L"record_05");
	// itemSID.push_back(L"record_06");
	// itemSID.push_back(L"record_07");
	// itemSID.push_back(L"record_08");
	// itemSID.push_back(L"record_09");
	// itemSID.push_back(L"record_10");
	// itemSID.push_back(L"record_11");
	// itemSID.push_back(L"record_12");
	itemSID[385] = L"fireball";
	itemSID[389] = L"item_frame";
	itemSID[388] = L"emerald";
	itemSID[390] = L"flower_pot";
	itemSID[391] = L"carrots";
	itemSID[392] = L"potato";
	itemSID[393] = L"potato_baked";
	itemSID[394] = L"potato_poisonous";
	itemSID[395] = L"empty_map";
	itemSID[396] = L"carrot_golden";
	itemSID[398] = L"carrot_on_a_stick";
	itemSID[399] = L"nether_star";
	itemSID[400] = L"pumpkin_pie";
	itemSID[401] = L"fireworks";
	itemSID[402] = L"fireworks_charge";
	itemSID[403] = L"enchanted_book";
	itemSID[404] = L"comparator";
	itemSID[405] = L"netherbrick";
	itemSID[406] = L"nether_quartz";
	itemSID[407] = L"minecart_tnt";
	itemSID[408] = L"minecart_hopper";
	itemSID[417] = L"horse_armor_metal";
	itemSID[418] = L"horse_armor_gold";
	itemSID[419] = L"horse_armor_diamond";
	itemSID[420] = L"lead";
	itemSID[421] = L"name_tag";
	itemSID[422] = L"netherite_ingot";
	Item::sword_wood		= ( new WeaponItem(12, _Tier::WOOD) )		->setBaseItemTypeAndMaterial(eBaseItemType_sword,	eMaterial_wood)		->setIconName(L"swordWood")->setDescriptionId(IDS_ITEM_SWORD_WOOD)->setUseDescriptionId(IDS_DESC_SWORD);
	Item::sword_stone		= ( new WeaponItem(16, _Tier::STONE) )		->setBaseItemTypeAndMaterial(eBaseItemType_sword,	eMaterial_stone)	->setIconName(L"swordStone")->setDescriptionId(IDS_ITEM_SWORD_STONE)->setUseDescriptionId(IDS_DESC_SWORD);
	Item::sword_iron		= ( new WeaponItem(11, _Tier::IRON) )		->setBaseItemTypeAndMaterial(eBaseItemType_sword,	eMaterial_iron)		->setIconName(L"swordIron")->setDescriptionId(IDS_ITEM_SWORD_IRON)->setUseDescriptionId(IDS_DESC_SWORD);
	Item::sword_diamond		= ( new WeaponItem(20, _Tier::DIAMOND) )	->setBaseItemTypeAndMaterial(eBaseItemType_sword,	eMaterial_diamond)	->setIconName(L"swordDiamond")->setDescriptionId(IDS_ITEM_SWORD_DIAMOND)->setUseDescriptionId(IDS_DESC_SWORD);
	Item::sword_gold		= ( new WeaponItem(27, _Tier::GOLD) )		->setBaseItemTypeAndMaterial(eBaseItemType_sword,	eMaterial_gold)		->setIconName(L"swordGold")->setDescriptionId(IDS_ITEM_SWORD_GOLD)->setUseDescriptionId(IDS_DESC_SWORD);

	Item::shovel_wood		= ( new ShovelItem(13, _Tier::WOOD) )		->setBaseItemTypeAndMaterial(eBaseItemType_shovel,	eMaterial_wood)		->setIconName(L"shovelWood")->setDescriptionId(IDS_ITEM_SHOVEL_WOOD)->setUseDescriptionId(IDS_DESC_SHOVEL);
	Item::shovel_stone		= ( new ShovelItem(17, _Tier::STONE) )		->setBaseItemTypeAndMaterial(eBaseItemType_shovel,	eMaterial_stone)	->setIconName(L"shovelStone")->setDescriptionId(IDS_ITEM_SHOVEL_STONE)->setUseDescriptionId(IDS_DESC_SHOVEL);
	Item::shovel_iron		= ( new ShovelItem(0, _Tier::IRON) )		->setBaseItemTypeAndMaterial(eBaseItemType_shovel,	eMaterial_iron)		->setIconName(L"shovelIron")->setDescriptionId(IDS_ITEM_SHOVEL_IRON)->setUseDescriptionId(IDS_DESC_SHOVEL);
	Item::shovel_diamond	= ( new ShovelItem(21, _Tier::DIAMOND) )	->setBaseItemTypeAndMaterial(eBaseItemType_shovel,	eMaterial_diamond)	->setIconName(L"shovelDiamond")->setDescriptionId(IDS_ITEM_SHOVEL_DIAMOND)->setUseDescriptionId(IDS_DESC_SHOVEL);
	Item::shovel_gold		= ( new ShovelItem(28, _Tier::GOLD) )		->setBaseItemTypeAndMaterial(eBaseItemType_shovel,	eMaterial_gold)		->setIconName(L"shovelGold")->setDescriptionId(IDS_ITEM_SHOVEL_GOLD)->setUseDescriptionId(IDS_DESC_SHOVEL);

	Item::pickAxe_wood		= ( new PickaxeItem(14, _Tier::WOOD) )		->setBaseItemTypeAndMaterial(eBaseItemType_pickaxe,	eMaterial_wood)		->setIconName(L"pickaxeWood")->setDescriptionId(IDS_ITEM_PICKAXE_WOOD)->setUseDescriptionId(IDS_DESC_PICKAXE);
	Item::pickAxe_stone		= ( new PickaxeItem(18, _Tier::STONE) )		->setBaseItemTypeAndMaterial(eBaseItemType_pickaxe,	eMaterial_stone)	->setIconName(L"pickaxeStone")->setDescriptionId(IDS_ITEM_PICKAXE_STONE)->setUseDescriptionId(IDS_DESC_PICKAXE);
	Item::pickAxe_iron		= ( new PickaxeItem(1, _Tier::IRON) )		->setBaseItemTypeAndMaterial(eBaseItemType_pickaxe,	eMaterial_iron)		->setIconName(L"pickaxeIron")->setDescriptionId(IDS_ITEM_PICKAXE_IRON)->setUseDescriptionId(IDS_DESC_PICKAXE);
	Item::pickAxe_diamond	= ( new PickaxeItem(22, _Tier::DIAMOND) )	->setBaseItemTypeAndMaterial(eBaseItemType_pickaxe,	eMaterial_diamond)	->setIconName(L"pickaxeDiamond")->setDescriptionId(IDS_ITEM_PICKAXE_DIAMOND)->setUseDescriptionId(IDS_DESC_PICKAXE);
	Item::pickAxe_gold		= ( new PickaxeItem(29, _Tier::GOLD) )		->setBaseItemTypeAndMaterial(eBaseItemType_pickaxe,	eMaterial_gold)		->setIconName(L"pickaxeGold")->setDescriptionId(IDS_ITEM_PICKAXE_GOLD)->setUseDescriptionId(IDS_DESC_PICKAXE);

	Item::hatchet_wood		= ( new HatchetItem(15, _Tier::WOOD) )		->setBaseItemTypeAndMaterial(eBaseItemType_hatchet,	eMaterial_wood)		->setIconName(L"hatchetWood")->setDescriptionId(IDS_ITEM_HATCHET_WOOD)->setUseDescriptionId(IDS_DESC_HATCHET);
	Item::hatchet_stone		= ( new HatchetItem(19, _Tier::STONE) )		->setBaseItemTypeAndMaterial(eBaseItemType_hatchet,	eMaterial_stone)	->setIconName(L"hatchetStone")->setDescriptionId(IDS_ITEM_HATCHET_STONE)->setUseDescriptionId(IDS_DESC_HATCHET);
	Item::hatchet_iron		= ( new HatchetItem(2, _Tier::IRON) )		->setBaseItemTypeAndMaterial(eBaseItemType_hatchet,	eMaterial_iron)		->setIconName(L"hatchetIron")->setDescriptionId(IDS_ITEM_HATCHET_IRON)->setUseDescriptionId(IDS_DESC_HATCHET);
	Item::hatchet_diamond	= ( new HatchetItem(23, _Tier::DIAMOND) )	->setBaseItemTypeAndMaterial(eBaseItemType_hatchet,	eMaterial_diamond)	->setIconName(L"hatchetDiamond")->setDescriptionId(IDS_ITEM_HATCHET_DIAMOND)->setUseDescriptionId(IDS_DESC_HATCHET);
	Item::hatchet_gold		= ( new HatchetItem(30, _Tier::GOLD) )		->setBaseItemTypeAndMaterial(eBaseItemType_hatchet,	eMaterial_gold)		->setIconName(L"hatchetGold")->setDescriptionId(IDS_ITEM_HATCHET_GOLD)->setUseDescriptionId(IDS_DESC_HATCHET);

	Item::hoe_wood			= ( new HoeItem(34, _Tier::WOOD) )			->setBaseItemTypeAndMaterial(eBaseItemType_hoe,	eMaterial_wood)		->setIconName(L"hoeWood")->setDescriptionId(IDS_ITEM_HOE_WOOD)->setUseDescriptionId(IDS_DESC_HOE);
	Item::hoe_stone			= ( new HoeItem(35, _Tier::STONE) )			->setBaseItemTypeAndMaterial(eBaseItemType_hoe,	eMaterial_stone)	->setIconName(L"hoeStone")->setDescriptionId(IDS_ITEM_HOE_STONE)->setUseDescriptionId(IDS_DESC_HOE);
	Item::hoe_iron			= ( new HoeItem(36, _Tier::IRON) )			->setBaseItemTypeAndMaterial(eBaseItemType_hoe,	eMaterial_iron)		->setIconName(L"hoeIron")->setDescriptionId(IDS_ITEM_HOE_IRON)->setUseDescriptionId(IDS_DESC_HOE);
	Item::hoe_diamond		= ( new HoeItem(37, _Tier::DIAMOND) )		->setBaseItemTypeAndMaterial(eBaseItemType_hoe,	eMaterial_diamond)	->setIconName(L"hoeDiamond")->setDescriptionId(IDS_ITEM_HOE_DIAMOND)->setUseDescriptionId(IDS_DESC_HOE);
	Item::hoe_gold			= ( new HoeItem(38, _Tier::GOLD) )			->setBaseItemTypeAndMaterial(eBaseItemType_hoe,	eMaterial_gold)		->setIconName(L"hoeGold")->setDescriptionId(IDS_ITEM_HOE_GOLD)->setUseDescriptionId(IDS_DESC_HOE);

	Item::door_wood			= ( new DoorItem(68, Material::wood) )		->setBaseItemTypeAndMaterial(eBaseItemType_door,	eMaterial_wood)->setIconName(L"doorWood")->setDescriptionId(IDS_ITEM_DOOR_WOOD)->setUseDescriptionId(IDS_DESC_DOOR_WOOD);
	Item::door_iron			= ( new DoorItem(74, Material::metal) )		->setBaseItemTypeAndMaterial(eBaseItemType_door,	eMaterial_iron)->setIconName(L"doorIron")->setDescriptionId(IDS_ITEM_DOOR_IRON)->setUseDescriptionId(IDS_DESC_DOOR_IRON);

	Item::helmet_leather		= static_cast<ArmorItem *>((new ArmorItem(42, ArmorItem::ArmorMaterial::CLOTH, 0, ArmorItem::SLOT_HEAD))->setBaseItemTypeAndMaterial(eBaseItemType_helmet, eMaterial_cloth)->setIconName(L"helmetCloth")->setDescriptionId(IDS_ITEM_HELMET_CLOTH)->setUseDescriptionId(IDS_DESC_HELMET_LEATHER));
	Item::helmet_iron		= static_cast<ArmorItem *>((new ArmorItem(50, ArmorItem::ArmorMaterial::IRON, 2, ArmorItem::SLOT_HEAD))->setBaseItemTypeAndMaterial(eBaseItemType_helmet, eMaterial_iron)->setIconName(L"helmetIron")->setDescriptionId(IDS_ITEM_HELMET_IRON)->setUseDescriptionId(IDS_DESC_HELMET_IRON));
	Item::helmet_diamond	= static_cast<ArmorItem *>((new ArmorItem(54, ArmorItem::ArmorMaterial::DIAMOND, 3, ArmorItem::SLOT_HEAD))->setBaseItemTypeAndMaterial(eBaseItemType_helmet, eMaterial_diamond)->setIconName(L"helmetDiamond")->setDescriptionId(IDS_ITEM_HELMET_DIAMOND)->setUseDescriptionId(IDS_DESC_HELMET_DIAMOND));
	Item::helmet_gold		= static_cast<ArmorItem *>((new ArmorItem(58, ArmorItem::ArmorMaterial::GOLD, 4, ArmorItem::SLOT_HEAD))->setBaseItemTypeAndMaterial(eBaseItemType_helmet, eMaterial_gold)->setIconName(L"helmetGold")->setDescriptionId(IDS_ITEM_HELMET_GOLD)->setUseDescriptionId(IDS_DESC_HELMET_GOLD));

	Item::chestplate_leather	= static_cast<ArmorItem *>((new ArmorItem(43, ArmorItem::ArmorMaterial::CLOTH, 0, ArmorItem::SLOT_TORSO))->setBaseItemTypeAndMaterial(eBaseItemType_chestplate, eMaterial_cloth)->setIconName(L"chestplateCloth")->setDescriptionId(IDS_ITEM_CHESTPLATE_CLOTH)->setUseDescriptionId(IDS_DESC_CHESTPLATE_LEATHER));
	Item::chestplate_iron		= static_cast<ArmorItem *>((new ArmorItem(51, ArmorItem::ArmorMaterial::IRON, 2, ArmorItem::SLOT_TORSO))->setBaseItemTypeAndMaterial(eBaseItemType_chestplate, eMaterial_iron)->setIconName(L"chestplateIron")->setDescriptionId(IDS_ITEM_CHESTPLATE_IRON)->setUseDescriptionId(IDS_DESC_CHESTPLATE_IRON));
	Item::chestplate_diamond	= static_cast<ArmorItem *>((new ArmorItem(55, ArmorItem::ArmorMaterial::DIAMOND, 3, ArmorItem::SLOT_TORSO))->setBaseItemTypeAndMaterial(eBaseItemType_chestplate, eMaterial_diamond)->setIconName(L"chestplateDiamond")->setDescriptionId(IDS_ITEM_CHESTPLATE_DIAMOND)->setUseDescriptionId(IDS_DESC_CHESTPLATE_DIAMOND));
	Item::chestplate_gold		= static_cast<ArmorItem *>((new ArmorItem(59, ArmorItem::ArmorMaterial::GOLD, 4, ArmorItem::SLOT_TORSO))->setBaseItemTypeAndMaterial(eBaseItemType_chestplate, eMaterial_gold)->setIconName(L"chestplateGold")->setDescriptionId(IDS_ITEM_CHESTPLATE_GOLD)->setUseDescriptionId(IDS_DESC_CHESTPLATE_GOLD));

	Item::leggings_leather	= static_cast<ArmorItem *>((new ArmorItem(44, ArmorItem::ArmorMaterial::CLOTH, 0, ArmorItem::SLOT_LEGS))->setBaseItemTypeAndMaterial(eBaseItemType_leggings, eMaterial_cloth)->setIconName(L"leggingsCloth")->setDescriptionId(IDS_ITEM_LEGGINGS_CLOTH)->setUseDescriptionId(IDS_DESC_LEGGINGS_LEATHER));
	Item::leggings_iron		= static_cast<ArmorItem *>((new ArmorItem(52, ArmorItem::ArmorMaterial::IRON, 2, ArmorItem::SLOT_LEGS))->setBaseItemTypeAndMaterial(eBaseItemType_leggings, eMaterial_iron)->setIconName(L"leggingsIron")->setDescriptionId(IDS_ITEM_LEGGINGS_IRON)->setUseDescriptionId(IDS_DESC_LEGGINGS_IRON));
	Item::leggings_diamond	= static_cast<ArmorItem *>((new ArmorItem(56, ArmorItem::ArmorMaterial::DIAMOND, 3, ArmorItem::SLOT_LEGS))->setBaseItemTypeAndMaterial(eBaseItemType_leggings, eMaterial_diamond)->setIconName(L"leggingsDiamond")->setDescriptionId(IDS_ITEM_LEGGINGS_DIAMOND)->setUseDescriptionId(IDS_DESC_LEGGINGS_DIAMOND));
	Item::leggings_gold		= static_cast<ArmorItem *>((new ArmorItem(60, ArmorItem::ArmorMaterial::GOLD, 4, ArmorItem::SLOT_LEGS))->setBaseItemTypeAndMaterial(eBaseItemType_leggings, eMaterial_gold)->setIconName(L"leggingsGold")->setDescriptionId(IDS_ITEM_LEGGINGS_GOLD)->setUseDescriptionId(IDS_DESC_LEGGINGS_GOLD));

	Item::helmet_chain		= static_cast<ArmorItem *>((new ArmorItem(46, ArmorItem::ArmorMaterial::CHAIN, 1, ArmorItem::SLOT_HEAD))->setBaseItemTypeAndMaterial(eBaseItemType_helmet, eMaterial_chain)->setIconName(L"helmetChain")->setDescriptionId(IDS_ITEM_HELMET_CHAIN)->setUseDescriptionId(IDS_DESC_HELMET_CHAIN));
	Item::chestplate_chain	= static_cast<ArmorItem *>((new ArmorItem(47, ArmorItem::ArmorMaterial::CHAIN, 1, ArmorItem::SLOT_TORSO))->setBaseItemTypeAndMaterial(eBaseItemType_chestplate, eMaterial_chain)->setIconName(L"chestplateChain")->setDescriptionId(IDS_ITEM_CHESTPLATE_CHAIN)->setUseDescriptionId(IDS_DESC_CHESTPLATE_CHAIN));
	Item::leggings_chain	= static_cast<ArmorItem *>((new ArmorItem(48, ArmorItem::ArmorMaterial::CHAIN, 1, ArmorItem::SLOT_LEGS))->setBaseItemTypeAndMaterial(eBaseItemType_leggings, eMaterial_chain)->setIconName(L"leggingsChain")->setDescriptionId(IDS_ITEM_LEGGINGS_CHAIN)->setUseDescriptionId(IDS_DESC_LEGGINGS_CHAIN));
	Item::boots_chain		= static_cast<ArmorItem *>((new ArmorItem(49, ArmorItem::ArmorMaterial::CHAIN, 1, ArmorItem::SLOT_FEET))->setBaseItemTypeAndMaterial(eBaseItemType_boots, eMaterial_chain)->setIconName(L"bootsChain")->setDescriptionId(IDS_ITEM_BOOTS_CHAIN)->setUseDescriptionId(IDS_DESC_BOOTS_CHAIN));

	Item::boots_leather		= static_cast<ArmorItem *>((new ArmorItem(45, ArmorItem::ArmorMaterial::CLOTH, 0, ArmorItem::SLOT_FEET))->setBaseItemTypeAndMaterial(eBaseItemType_boots, eMaterial_cloth)->setIconName(L"bootsCloth")->setDescriptionId(IDS_ITEM_BOOTS_CLOTH)->setUseDescriptionId(IDS_DESC_BOOTS_LEATHER));
	Item::boots_iron		= static_cast<ArmorItem *>((new ArmorItem(53, ArmorItem::ArmorMaterial::IRON, 2, ArmorItem::SLOT_FEET))->setBaseItemTypeAndMaterial(eBaseItemType_boots, eMaterial_iron)->setIconName(L"bootsIron")->setDescriptionId(IDS_ITEM_BOOTS_IRON)->setUseDescriptionId(IDS_DESC_BOOTS_IRON));
	Item::boots_diamond		= static_cast<ArmorItem *>((new ArmorItem(57, ArmorItem::ArmorMaterial::DIAMOND, 3, ArmorItem::SLOT_FEET))->setBaseItemTypeAndMaterial(eBaseItemType_boots, eMaterial_diamond)->setIconName(L"bootsDiamond")->setDescriptionId(IDS_ITEM_BOOTS_DIAMOND)->setUseDescriptionId(IDS_DESC_BOOTS_DIAMOND));
	Item::boots_gold		= static_cast<ArmorItem *>((new ArmorItem(61, ArmorItem::ArmorMaterial::GOLD, 4, ArmorItem::SLOT_FEET))->setBaseItemTypeAndMaterial(eBaseItemType_boots, eMaterial_gold)->setIconName(L"bootsGold")->setDescriptionId(IDS_ITEM_BOOTS_GOLD)->setUseDescriptionId(IDS_DESC_BOOTS_GOLD));

	Item::ironIngot = ( new Item(9) )->setIconName(L"ingotIron")					->setBaseItemTypeAndMaterial(eBaseItemType_treasure,	eMaterial_iron)->setDescriptionId(IDS_ITEM_INGOT_IRON)->setUseDescriptionId(IDS_DESC_INGOT);
	Item::goldIngot = ( new Item(10) )->setIconName(L"ingotGold")					->setBaseItemTypeAndMaterial(eBaseItemType_treasure,	eMaterial_gold)->setDescriptionId(IDS_ITEM_INGOT_GOLD)->setUseDescriptionId(IDS_DESC_INGOT);


	// 4J-PB - todo - add materials and base types to the ones below
	Item::bucket_empty		= ( new BucketItem(69, 0) )					->setBaseItemTypeAndMaterial(eBaseItemType_utensil,	eMaterial_water)->setIconName(L"bucket")->setDescriptionId(IDS_ITEM_BUCKET)->setUseDescriptionId(IDS_DESC_BUCKET)->setMaxStackSize(16);
	Item::bowl = ( new Item(25) )										->setBaseItemTypeAndMaterial(eBaseItemType_utensil,	eMaterial_wood)->setIconName(L"bowl")->setDescriptionId(IDS_ITEM_BOWL)->setUseDescriptionId(IDS_DESC_BOWL)->setMaxStackSize(64);

	Item::bucket_water		= ( new BucketItem(70, Tile::water_Id) )	->setIconName(L"bucketWater")->setDescriptionId(IDS_ITEM_BUCKET_WATER)->setCraftingRemainingItem(Item::bucket_empty)->setUseDescriptionId(IDS_DESC_BUCKET_WATER);
	Item::bucket_lava		= ( new BucketItem(71, Tile::lava_Id) )		->setIconName(L"bucketLava")->setDescriptionId(IDS_ITEM_BUCKET_LAVA)->setCraftingRemainingItem(Item::bucket_empty)->setUseDescriptionId(IDS_DESC_BUCKET_LAVA);
	Item::bucket_milk				= ( new MilkBucketItem(79) )->setIconName(L"milk")->setDescriptionId(IDS_ITEM_BUCKET_MILK)->setCraftingRemainingItem(Item::bucket_empty)->setUseDescriptionId(IDS_DESC_BUCKET_MILK);

	Item::bow = static_cast<BowItem *>((new BowItem(5))->setIconName(L"bow")->setBaseItemTypeAndMaterial(eBaseItemType_bow, eMaterial_bow)->setDescriptionId(IDS_ITEM_BOW)->setUseDescriptionId(IDS_DESC_BOW));
	Item::arrow = ( new Item(6) )													->setIconName(L"arrow")->setBaseItemTypeAndMaterial(eBaseItemType_bow,	eMaterial_arrow)	->setDescriptionId(IDS_ITEM_ARROW)->setUseDescriptionId(IDS_DESC_ARROW);

	Item::compass = ( new CompassItem(89) )											->setIconName(L"compass")->setBaseItemTypeAndMaterial(eBaseItemType_pockettool,	eMaterial_compass)		->setDescriptionId(IDS_ITEM_COMPASS)->setUseDescriptionId(IDS_DESC_COMPASS);
	Item::clock = ( new ClockItem(91) )												->setIconName(L"clock")->setBaseItemTypeAndMaterial(eBaseItemType_pockettool,	eMaterial_clock)		->setDescriptionId(IDS_ITEM_CLOCK)->setUseDescriptionId(IDS_DESC_CLOCK);
	Item::map = static_cast<MapItem *>((new MapItem(102))->setIconName(L"map")->setBaseItemTypeAndMaterial(eBaseItemType_pockettool, eMaterial_map)->setDescriptionId(IDS_ITEM_MAP)->setUseDescriptionId(IDS_DESC_MAP));

	Item::flintAndSteel = ( new FlintAndSteelItem(3) )								->setIconName(L"flintAndSteel")->setBaseItemTypeAndMaterial(eBaseItemType_devicetool,	eMaterial_flintandsteel)->setDescriptionId(IDS_ITEM_FLINT_AND_STEEL)->setUseDescriptionId(IDS_DESC_FLINTANDSTEEL);
	Item::apple = ( new FoodItem(4, 4, FoodConstants::FOOD_SATURATION_LOW, false) )	->setIconName(L"apple")->setDescriptionId(IDS_ITEM_APPLE)->setUseDescriptionId(IDS_DESC_APPLE);
	Item::coal = ( new CoalItem(7) )												->setBaseItemTypeAndMaterial(eBaseItemType_treasure,	eMaterial_coal)->setIconName(L"coal")->setDescriptionId(IDS_ITEM_COAL)->setUseDescriptionId(IDS_DESC_COAL);
	Item::diamond = ( new Item(8) )													->setBaseItemTypeAndMaterial(eBaseItemType_treasure,	eMaterial_diamond)->setIconName(L"diamond")->setDescriptionId(IDS_ITEM_DIAMOND)->setUseDescriptionId(IDS_DESC_DIAMONDS);
	Item::stick = ( new Item(24) )													->setIconName(L"stick")->handEquipped()->setDescriptionId(IDS_ITEM_STICK)->setUseDescriptionId(IDS_DESC_STICK);
	Item::mushroomStew = ( new BowlFoodItem(26, 6) )								->setIconName(L"mushroomStew")->setDescriptionId(IDS_ITEM_MUSHROOM_STEW)->setUseDescriptionId(IDS_DESC_MUSHROOMSTEW);

	Item::string = ( new TilePlanterItem(31, Tile::tripWire) )						->setIconName(L"string")->setDescriptionId(IDS_ITEM_STRING)->setUseDescriptionId(IDS_DESC_STRING);
	Item::feather = ( new Item(32) )												->setIconName(L"feather")->setDescriptionId(IDS_ITEM_FEATHER)->setUseDescriptionId(IDS_DESC_FEATHER);
	Item::gunpowder = ( new Item(33) )												->setIconName(L"sulphur")->setDescriptionId(IDS_ITEM_SULPHUR)->setUseDescriptionId(IDS_DESC_SULPHUR)->setPotionBrewingFormula(PotionBrewing::MOD_GUNPOWDER);


	Item::seeds_wheat = ( new SeedItem(39, Tile::wheat_Id, Tile::farmland_Id) )			->setIconName(L"seeds")->setDescriptionId(IDS_ITEM_WHEAT_SEEDS)->setUseDescriptionId(IDS_DESC_WHEAT_SEEDS);
	Item::wheat = ( new Item(40) )														->setBaseItemTypeAndMaterial(eBaseItemType_treasure,	eMaterial_wheat)->setIconName(L"wheat")->setDescriptionId(IDS_ITEM_WHEAT)->setUseDescriptionId(IDS_DESC_WHEAT);
	Item::bread = ( new FoodItem(41, 5, FoodConstants::FOOD_SATURATION_NORMAL, false) )	->setIconName(L"bread")->setDescriptionId(IDS_ITEM_BREAD)->setUseDescriptionId(IDS_DESC_BREAD);


	Item::flint = ( new Item(62) )																->setIconName(L"flint")->setDescriptionId(IDS_ITEM_FLINT)->setUseDescriptionId(IDS_DESC_FLINT);
	Item::porkChop_raw = ( new FoodItem(63, 3, FoodConstants::FOOD_SATURATION_LOW, true) )		->setIconName(L"porkchopRaw")->setDescriptionId(IDS_ITEM_PORKCHOP_RAW)->setUseDescriptionId(IDS_DESC_PORKCHOP_RAW);
	Item::porkChop_cooked = ( new FoodItem(64, 8, FoodConstants::FOOD_SATURATION_GOOD, true) )	->setIconName(L"porkchopCooked")->setDescriptionId(IDS_ITEM_PORKCHOP_COOKED)->setUseDescriptionId(IDS_DESC_PORKCHOP_COOKED);
	Item::painting = ( new HangingEntityItem(65,eTYPE_PAINTING) )								->setBaseItemTypeAndMaterial(eBaseItemType_HangingItem,	eMaterial_cloth)->setIconName(L"painting")->setDescriptionId(IDS_ITEM_PAINTING)->setUseDescriptionId(IDS_DESC_PICTURE);

	Item::apple_gold = ( new GoldenAppleItem(66, 4, FoodConstants::FOOD_SATURATION_SUPERNATURAL, false) )->setCanAlwaysEat()->setEatEffect(MobEffect::regeneration->id, 5, 1, 1.0f)
																										->setBaseItemTypeAndMaterial(eBaseItemType_giltFruit,eMaterial_apple)->setIconName(L"appleGold")->setDescriptionId(IDS_ITEM_APPLE_GOLD);//->setUseDescriptionId(IDS_DESC_GOLDENAPPLE);

	Item::sign = ( new SignItem(67) )															->setBaseItemTypeAndMaterial(eBaseItemType_HangingItem, eMaterial_wood)->setIconName(L"sign")->setDescriptionId(IDS_ITEM_SIGN)->setUseDescriptionId(IDS_DESC_SIGN);



	Item::minecart = ( new MinecartItem(72, Minecart::TYPE_RIDEABLE) )		->setIconName(L"minecart")->setDescriptionId(IDS_ITEM_MINECART)->setUseDescriptionId(IDS_DESC_MINECART);
	Item::saddle = ( new SaddleItem(73) )								->setIconName(L"saddle")->setDescriptionId(IDS_ITEM_SADDLE)->setUseDescriptionId(IDS_DESC_SADDLE);
	Item::redStone = ( new RedStoneItem(75) )							->setBaseItemTypeAndMaterial(eBaseItemType_treasure,	eMaterial_redstone)->setIconName(L"redstone")->setDescriptionId(IDS_ITEM_REDSTONE)->setUseDescriptionId(IDS_DESC_REDSTONE_DUST)->setPotionBrewingFormula(PotionBrewing::MOD_REDSTONE);
	Item::snowBall = ( new SnowballItem(76) )							->setIconName(L"snowball")->setDescriptionId(IDS_ITEM_SNOWBALL)->setUseDescriptionId(IDS_DESC_SNOWBALL);

	Item::boat = ( new BoatItem(77) )									->setIconName(L"boat")->setDescriptionId(IDS_ITEM_BOAT)->setUseDescriptionId(IDS_DESC_BOAT);

	Item::leather = ( new Item(78) )									->setIconName(L"leather")->setDescriptionId(IDS_ITEM_LEATHER)->setUseDescriptionId(IDS_DESC_LEATHER);
	Item::brick = ( new Item(80) )										->setIconName(L"brick")->setDescriptionId(IDS_ITEM_BRICK)->setUseDescriptionId(IDS_DESC_BRICK);
	Item::clay = ( new Item(81) )										->setIconName(L"clay")->setDescriptionId(IDS_ITEM_CLAY)->setUseDescriptionId(IDS_DESC_CLAY);
	Item::reeds = ( new TilePlanterItem(82, Tile::reeds) )				->setIconName(L"reeds")->setDescriptionId(IDS_ITEM_REEDS)->setUseDescriptionId(IDS_DESC_REEDS);
	Item::paper = ( new Item(83) )										->setBaseItemTypeAndMaterial(Item::eBaseItemType_paper, Item::eMaterial_paper)->setIconName(L"paper")->setDescriptionId(IDS_ITEM_PAPER)->setUseDescriptionId(IDS_DESC_PAPER);
	Item::book = ( new BookItem(84) )									->setBaseItemTypeAndMaterial(Item::eBaseItemType_paper, Item::eMaterial_book)->setIconName(L"book")->setDescriptionId(IDS_ITEM_BOOK)->setUseDescriptionId(IDS_DESC_BOOK);
	Item::slimeBall = ( new Item(85) )									->setIconName(L"slimeball")->setDescriptionId(IDS_ITEM_SLIMEBALL)->setUseDescriptionId(IDS_DESC_SLIMEBALL);
	Item::minecart_chest = ( new MinecartItem(86, Minecart::TYPE_CHEST) )	->setIconName(L"minecart_chest")->setDescriptionId(IDS_ITEM_MINECART_CHEST)->setUseDescriptionId(IDS_DESC_MINECARTWITHCHEST);
	Item::minecart_furnace = ( new MinecartItem(87, Minecart::TYPE_FURNACE) )->setIconName(L"minecart_furnace")->setDescriptionId(IDS_ITEM_MINECART_FURNACE)->setUseDescriptionId(IDS_DESC_MINECARTWITHFURNACE);
	Item::egg = ( new EggItem(88) )										->setIconName(L"egg")->setDescriptionId(IDS_ITEM_EGG)->setUseDescriptionId(IDS_DESC_EGG);
	Item::fishingRod = static_cast<FishingRodItem *>((new FishingRodItem(90))->setBaseItemTypeAndMaterial(eBaseItemType_rod, eMaterial_wood)->setIconName(L"fishingRod")->setDescriptionId(IDS_ITEM_FISHING_ROD)->setUseDescriptionId(IDS_DESC_FISHINGROD));
	Item::yellowDust = ( new Item(92) )									->setIconName(L"yellowDust")->setDescriptionId(IDS_ITEM_YELLOW_DUST)->setUseDescriptionId(IDS_DESC_YELLOW_DUST)->setPotionBrewingFormula(PotionBrewing::MOD_GLOWSTONE);
	Item::fish_raw = ( new FoodItem(93, 2, FoodConstants::FOOD_SATURATION_LOW, false) )			->setIconName(L"fishRaw")->setDescriptionId(IDS_ITEM_FISH_RAW)->setUseDescriptionId(IDS_DESC_FISH_RAW);
	Item::fish_cooked = ( new FoodItem(94, 5, FoodConstants::FOOD_SATURATION_NORMAL, false) )	->setIconName(L"fishCooked")->setDescriptionId(IDS_ITEM_FISH_COOKED)->setUseDescriptionId(IDS_DESC_FISH_COOKED);

	Item::dye_powder = ( new DyePowderItem(95) )			->setBaseItemTypeAndMaterial(eBaseItemType_dyepowder,	eMaterial_dye)->setIconName(L"dyePowder")->setDescriptionId(IDS_ITEM_DYE_POWDER)->setUseDescriptionId(-1);

	Item::bone = ( new Item(96) )										->setIconName(L"bone")->setDescriptionId(IDS_ITEM_BONE)->handEquipped()->setUseDescriptionId(IDS_DESC_BONE);
	Item::sugar = ( new Item(97) )										->setIconName(L"sugar")->setDescriptionId(IDS_ITEM_SUGAR)->setUseDescriptionId(IDS_DESC_SUGAR)->setPotionBrewingFormula(PotionBrewing::MOD_SUGAR);
	// 4J-PB  - changing the cake to be stackable - Jens ok'ed this 23/10/12
	//Item::cake = ( new TilePlanterItem(98, Tile::cake) )->setMaxStackSize(1)->setIcon(13, 1)->setDescriptionId(IDS_ITEM_CAKE)->setUseDescriptionId(IDS_DESC_CAKE);
	Item::cake = ( new TilePlanterItem(98, Tile::cake) )				->setIconName(L"cake")->setDescriptionId(IDS_ITEM_CAKE)->setUseDescriptionId(IDS_DESC_CAKE);

	Item::bed = ( new BedItem(99) )										->setMaxStackSize(1)->setIconName(L"bed")->setDescriptionId(IDS_ITEM_BED)->setUseDescriptionId(IDS_DESC_BED);

	Item::repeater = ( new TilePlanterItem(100, static_cast<Tile *>(Tile::diode_off)) )			->setIconName(L"diode")->setDescriptionId(IDS_ITEM_DIODE)->setUseDescriptionId(IDS_DESC_REDSTONEREPEATER);
	Item::cookie = ( new FoodItem(101, 2, FoodConstants::FOOD_SATURATION_POOR, false) )	->setIconName(L"cookie")->setDescriptionId(IDS_ITEM_COOKIE)->setUseDescriptionId(IDS_DESC_COOKIE);


	Item::shears = static_cast<ShearsItem *>((new ShearsItem(103))->setIconName(L"shears")->setBaseItemTypeAndMaterial(eBaseItemType_devicetool, eMaterial_shears)->setDescriptionId(IDS_ITEM_SHEARS)->setUseDescriptionId(IDS_DESC_SHEARS));

	Item::melon = (new FoodItem(104, 2, FoodConstants::FOOD_SATURATION_LOW, false))		->setIconName(L"melon")->setDescriptionId(IDS_ITEM_MELON_SLICE)->setUseDescriptionId(IDS_DESC_MELON_SLICE);

	Item::seeds_pumpkin = (new SeedItem(105, Tile::pumpkinStem_Id, Tile::farmland_Id))	->setIconName(L"seeds_pumpkin")->setBaseItemTypeAndMaterial(eBaseItemType_seed,	eMaterial_pumpkin)->setDescriptionId(IDS_ITEM_PUMPKIN_SEEDS)->setUseDescriptionId(IDS_DESC_PUMPKIN_SEEDS);
	Item::seeds_melon = (new SeedItem(106, Tile::melonStem_Id, Tile::farmland_Id))		->setIconName(L"seeds_melon")->setBaseItemTypeAndMaterial(eBaseItemType_seed,	eMaterial_melon)->setDescriptionId(IDS_ITEM_MELON_SEEDS)->setUseDescriptionId(IDS_DESC_MELON_SEEDS);

	Item::beef_raw = (new FoodItem(107, 3, FoodConstants::FOOD_SATURATION_LOW, true))	->setIconName(L"beefRaw")->setDescriptionId(IDS_ITEM_BEEF_RAW)->setUseDescriptionId(IDS_DESC_BEEF_RAW);
	Item::beef_cooked = (new FoodItem(108, 8, FoodConstants::FOOD_SATURATION_GOOD, true))->setIconName(L"beefCooked")->setDescriptionId(IDS_ITEM_BEEF_COOKED)->setUseDescriptionId(IDS_DESC_BEEF_COOKED);
	Item::chicken_raw = (new FoodItem(109, 2, FoodConstants::FOOD_SATURATION_LOW, true))->setEatEffect(MobEffect::hunger->id, 30, 0, .3f)->setIconName(L"chickenRaw")->setDescriptionId(IDS_ITEM_CHICKEN_RAW)->setUseDescriptionId(IDS_DESC_CHICKEN_RAW);
	Item::chicken_cooked = (new FoodItem(110, 6, FoodConstants::FOOD_SATURATION_NORMAL, true))->setIconName(L"chickenCooked")->setDescriptionId(IDS_ITEM_CHICKEN_COOKED)->setUseDescriptionId(IDS_DESC_CHICKEN_COOKED);
	Item::rotten_flesh = (new FoodItem(111, 4, FoodConstants::FOOD_SATURATION_POOR, true))->setEatEffect(MobEffect::hunger->id, 30, 0, .8f)->setIconName(L"rottenFlesh")->setDescriptionId(IDS_ITEM_ROTTEN_FLESH)->setUseDescriptionId(IDS_DESC_ROTTEN_FLESH);

	Item::enderPearl =			(new EnderpearlItem(112))											->setIconName(L"enderPearl")->setDescriptionId(IDS_ITEM_ENDER_PEARL)->setUseDescriptionId(IDS_DESC_ENDER_PEARL);

	Item::blazeRod =			(new Item(113)	)													->setIconName(L"blazeRod")->setDescriptionId(IDS_ITEM_BLAZE_ROD)->setUseDescriptionId(IDS_DESC_BLAZE_ROD)->handEquipped();
	Item::ghastTear =			(new Item(114) )													->setIconName(L"ghastTear")->setDescriptionId(IDS_ITEM_GHAST_TEAR)->setUseDescriptionId(IDS_DESC_GHAST_TEAR)->setPotionBrewingFormula(PotionBrewing::MOD_GHASTTEARS);
	Item::goldNugget =			(new Item(115) )													->setBaseItemTypeAndMaterial(eBaseItemType_treasure,	eMaterial_gold)->setIconName(L"goldNugget")->setDescriptionId(IDS_ITEM_GOLD_NUGGET)->setUseDescriptionId(IDS_DESC_GOLD_NUGGET);

	Item::netherwart_seeds =	(new SeedItem(116, Tile::netherStalk_Id, Tile::soulsand_Id) )		->setIconName(L"netherStalkSeeds")->setDescriptionId(IDS_ITEM_NETHER_STALK_SEEDS)->setUseDescriptionId(IDS_DESC_NETHER_STALK_SEEDS)->setPotionBrewingFormula(PotionBrewing::MOD_NETHERWART);

	Item::potion =				static_cast<PotionItem *>((new PotionItem(117))->setIconName(L"potion")->setDescriptionId(IDS_ITEM_POTION)->setUseDescriptionId(IDS_DESC_POTION));
	Item::glassBottle =			(new BottleItem(118) )												->setBaseItemTypeAndMaterial(eBaseItemType_utensil,	eMaterial_glass)->setIconName(L"glassBottle")->setDescriptionId(IDS_ITEM_GLASS_BOTTLE)->setUseDescriptionId(IDS_DESC_GLASS_BOTTLE);

	Item::spiderEye =			(new FoodItem(119, 2, FoodConstants::FOOD_SATURATION_GOOD, false) )	->setEatEffect(MobEffect::poison->id, 5, 0, 1.0f)->setIconName(L"spiderEye")->setDescriptionId(IDS_ITEM_SPIDER_EYE)->setUseDescriptionId(IDS_DESC_SPIDER_EYE)->setPotionBrewingFormula(PotionBrewing::MOD_SPIDEREYE);
	Item::fermentedSpiderEye =	(new Item(120) )													->setIconName(L"fermentedSpiderEye")->setDescriptionId(IDS_ITEM_FERMENTED_SPIDER_EYE)->setUseDescriptionId(IDS_DESC_FERMENTED_SPIDER_EYE)->setPotionBrewingFormula(PotionBrewing::MOD_FERMENTEDEYE);

	Item::blazePowder =			(new Item(121) )													->setIconName(L"blazePowder")->setDescriptionId(IDS_ITEM_BLAZE_POWDER)->setUseDescriptionId(IDS_DESC_BLAZE_POWDER)->setPotionBrewingFormula(PotionBrewing::MOD_BLAZEPOWDER);
	Item::magmaCream =			(new Item(122) )													->setIconName(L"magmaCream")->setDescriptionId(IDS_ITEM_MAGMA_CREAM)->setUseDescriptionId(IDS_DESC_MAGMA_CREAM)->setPotionBrewingFormula(PotionBrewing::MOD_MAGMACREAM);

	Item::brewingStand =		(new TilePlanterItem(123, Tile::brewingStand) )						->setBaseItemTypeAndMaterial(eBaseItemType_device,	eMaterial_blaze)->setIconName(L"brewingStand")->setDescriptionId(IDS_ITEM_BREWING_STAND)->setUseDescriptionId(IDS_DESC_BREWING_STAND);
	Item::cauldron =			(new TilePlanterItem(124, Tile::cauldron) )							->setBaseItemTypeAndMaterial(eBaseItemType_utensil,	eMaterial_iron)->setIconName(L"cauldron")->setDescriptionId(IDS_ITEM_CAULDRON)->setUseDescriptionId(IDS_DESC_CAULDRON);
	Item::eyeOfEnder =			(new EnderEyeItem(125) )											->setBaseItemTypeAndMaterial(eBaseItemType_pockettool,	eMaterial_ender)->setIconName(L"eyeOfEnder")->setDescriptionId(IDS_ITEM_EYE_OF_ENDER)->setUseDescriptionId(IDS_DESC_EYE_OF_ENDER);
	Item::speckledMelon =		(new Item(126) )													->setBaseItemTypeAndMaterial(eBaseItemType_giltFruit,	eMaterial_melon)->setIconName(L"speckledMelon")->setDescriptionId(IDS_ITEM_SPECKLED_MELON)->setUseDescriptionId(IDS_DESC_SPECKLED_MELON)->setPotionBrewingFormula(PotionBrewing::MOD_SPECKLEDMELON);

	Item::spawnEgg =			(new SpawnEggItem(127))												->setIconName(L"monsterPlacer")->setDescriptionId(IDS_ITEM_MONSTER_SPAWNER)->setUseDescriptionId(IDS_DESC_MONSTER_SPAWNER);

	// 4J Stu - Brought this forward
	Item::expBottle =			(new ExperienceItem(128))											->setIconName(L"expBottle")->setDescriptionId(IDS_ITEM_EXP_BOTTLE)->setUseDescriptionId(IDS_DESC_EXP_BOTTLE);

	Item::record_01 =			( new RecordingItem(2000, L"13") )									->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_01)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_02 =			( new RecordingItem(2001, L"cat") )									->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_02)->setUseDescriptionId(IDS_DESC_RECORD);

	// 4J - new records brought forward from 1.2.3
	Item::record_03 =			( new RecordingItem(2002, L"blocks") )								->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_03)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_04 =			( new RecordingItem(2003, L"chirp") )								->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_04)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_05 =			( new RecordingItem(2004, L"far") )									->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_05)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_06 =			( new RecordingItem(2005, L"mall") )								->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_06)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_07 =			( new RecordingItem(2006, L"mellohi") )								->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_07)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_09 =			( new RecordingItem(2007, L"stal") )								->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_08)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_10 =			( new RecordingItem(2008, L"strad") )								->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_09)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_11 =			( new RecordingItem(2009, L"ward") )								->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_10)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_12 =			( new RecordingItem(2010, L"11") )									->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_11)->setUseDescriptionId(IDS_DESC_RECORD);
	Item::record_08 =			( new RecordingItem(2011, L"where are we now") )					->setIconName(L"record")->setDescriptionId(IDS_ITEM_RECORD_12)->setUseDescriptionId(IDS_DESC_RECORD);

	// TU9
	// putting the fire charge in as a torch, so that it stacks without being near the middle of the selection boxes
	Item::fireball =			(new FireChargeItem(129))											->setBaseItemTypeAndMaterial(eBaseItemType_torch,	eMaterial_setfire)->setIconName(L"fireball")->setDescriptionId(IDS_ITEM_FIREBALL)->setUseDescriptionId(IDS_DESC_FIREBALL);
	Item::frame =				(new HangingEntityItem(133,eTYPE_ITEM_FRAME))						->setBaseItemTypeAndMaterial(eBaseItemType_HangingItem,	eMaterial_glass)->setIconName(L"frame")->setDescriptionId(IDS_ITEM_ITEMFRAME)->setUseDescriptionId(IDS_DESC_ITEMFRAME);


	// TU12
	Item::skull =				(new SkullItem(141))												->setIconName(L"skull")->setDescriptionId(IDS_ITEM_SKULL)->setUseDescriptionId(IDS_DESC_SKULL);

	// TU14
	//Item::writingBook = (new WritingBookItem(130))->setIcon(11, 11)->setDescriptionId("writingBook");
	//Item::writtenBook = (new WrittenBookItem(131))->setIcon(12, 11)->setDescriptionId("writtenBook");

	Item::emerald =				(new Item(132))														->setBaseItemTypeAndMaterial(eBaseItemType_treasure, eMaterial_emerald)->setIconName(L"emerald")->setDescriptionId(IDS_ITEM_EMERALD)->setUseDescriptionId(IDS_DESC_EMERALD);

	Item::flowerPot = (new TilePlanterItem(134, Tile::flowerPot))									->setIconName(L"flowerPot")->setDescriptionId(IDS_FLOWERPOT)->setUseDescriptionId(IDS_DESC_FLOWERPOT);

	Item::carrots = (new SeedFoodItem(135, 4, FoodConstants::FOOD_SATURATION_NORMAL, Tile::carrots_Id, Tile::farmland_Id))	->setIconName(L"carrots")->setDescriptionId(IDS_CARROTS)->setUseDescriptionId(IDS_DESC_CARROTS);
	Item::potato = (new SeedFoodItem(136, 1, FoodConstants::FOOD_SATURATION_LOW, Tile::potatoes_Id, Tile::farmland_Id))		->setIconName(L"potato")->setDescriptionId(IDS_POTATO)->setUseDescriptionId(IDS_DESC_POTATO);
	Item::potatoBaked = (new FoodItem(137, 6, FoodConstants::FOOD_SATURATION_NORMAL, false))								->setIconName(L"potatoBaked")->setDescriptionId(IDS_ITEM_POTATO_BAKED)->setUseDescriptionId(IDS_DESC_POTATO_BAKED);
	Item::potatoPoisonous = (new FoodItem(138, 2, FoodConstants::FOOD_SATURATION_LOW, false))								->setEatEffect(MobEffect::poison->id, 5, 0, .6f)->setIconName(L"potatoPoisonous")->setDescriptionId(IDS_ITEM_POTATO_POISONOUS)->setUseDescriptionId(IDS_DESC_POTATO_POISONOUS);

	Item::emptyMap = static_cast<EmptyMapItem *>((new EmptyMapItem(139))->setIconName(L"map_empty")->setDescriptionId(IDS_ITEM_MAP_EMPTY)->setUseDescriptionId(IDS_DESC_MAP_EMPTY));

	Item::carrotGolden = (new FoodItem(140, 6, FoodConstants::FOOD_SATURATION_SUPERNATURAL, false))			->setBaseItemTypeAndMaterial(eBaseItemType_giltFruit,	eMaterial_carrot)->setIconName(L"carrotGolden")->setPotionBrewingFormula(PotionBrewing::MOD_GOLDENCARROT)->setDescriptionId(IDS_ITEM_CARROT_GOLDEN)->setUseDescriptionId(IDS_DESC_CARROT_GOLDEN);

	Item::carrotOnAStick = (new CarrotOnAStickItem(142))													->setBaseItemTypeAndMaterial(eBaseItemType_rod, eMaterial_carrot)->setIconName(L"carrotOnAStick")->setDescriptionId(IDS_ITEM_CARROT_ON_A_STICK)->setUseDescriptionId(IDS_DESC_CARROT_ON_A_STICK);
	Item::netherStar = (new SimpleFoiledItem(143))													->setIconName(L"nether_star")->setDescriptionId(IDS_NETHER_STAR)->setUseDescriptionId(IDS_DESC_NETHER_STAR);
	Item::pumpkinPie = (new FoodItem(144, 8, FoodConstants::FOOD_SATURATION_LOW, false))			->setIconName(L"pumpkinPie")->setDescriptionId(IDS_ITEM_PUMPKIN_PIE)->setUseDescriptionId(IDS_DESC_PUMPKIN_PIE);
	Item::fireworks = (new FireworksItem(145))														->setBaseItemTypeAndMaterial(Item::eBaseItemType_fireworks,	Item::eMaterial_undefined)->setIconName(L"fireworks")->setDescriptionId(IDS_FIREWORKS)->setUseDescriptionId(IDS_DESC_FIREWORKS);
	Item::fireworksCharge = (new FireworksChargeItem(146))											->setBaseItemTypeAndMaterial(Item::eBaseItemType_fireworks,	Item::eMaterial_undefined)->setIconName(L"fireworks_charge")->setDescriptionId(IDS_FIREWORKS_CHARGE)->setUseDescriptionId(IDS_DESC_FIREWORKS_CHARGE);
	EnchantedBookItem::enchantedBook = static_cast<EnchantedBookItem *>((new EnchantedBookItem(147))->setMaxStackSize(1)->setIconName(L"enchantedBook")->setDescriptionId(IDS_ITEM_ENCHANTED_BOOK)->setUseDescriptionId(IDS_DESC_ENCHANTED_BOOK));
	Item::comparator = (new TilePlanterItem(148, Tile::comparator_off))								->setIconName(L"comparator")->setDescriptionId(IDS_ITEM_COMPARATOR)->setUseDescriptionId(IDS_DESC_COMPARATOR);
	Item::netherbrick =	(new Item(149))																->setIconName(L"netherbrick")->setDescriptionId(IDS_ITEM_NETHERBRICK)->setUseDescriptionId(IDS_DESC_ITEM_NETHERBRICK);
	Item::netherQuartz = (new Item(150))															->setIconName(L"netherquartz")->setDescriptionId(IDS_ITEM_NETHER_QUARTZ)->setUseDescriptionId(IDS_DESC_NETHER_QUARTZ);
	Item::minecart_tnt = (new MinecartItem(151, Minecart::TYPE_TNT))								->setIconName(L"minecart_tnt")->setDescriptionId(IDS_ITEM_MINECART_TNT)->setUseDescriptionId(IDS_DESC_MINECART_TNT);
	Item::minecart_hopper = (new MinecartItem(152, Minecart::TYPE_HOPPER))							->setIconName(L"minecart_hopper")->setDescriptionId(IDS_ITEM_MINECART_HOPPER)->setUseDescriptionId(IDS_DESC_MINECART_HOPPER);

	Item::horseArmorMetal = (new Item(161))															->setIconName(L"iron_horse_armor")->setMaxStackSize(1)->setDescriptionId(IDS_ITEM_IRON_HORSE_ARMOR)->setUseDescriptionId(IDS_DESC_IRON_HORSE_ARMOR);
	Item::horseArmorGold = (new Item(162))															->setIconName(L"gold_horse_armor")->setMaxStackSize(1)->setDescriptionId(IDS_ITEM_GOLD_HORSE_ARMOR)->setUseDescriptionId(IDS_DESC_GOLD_HORSE_ARMOR);
	Item::horseArmorDiamond = (new Item(163))														->setIconName(L"diamond_horse_armor")->setMaxStackSize(1)->setDescriptionId(IDS_ITEM_DIAMOND_HORSE_ARMOR)->setUseDescriptionId(IDS_DESC_DIAMOND_HORSE_ARMOR);
	Item::lead = (new LeashItem(164))																->setBaseItemTypeAndMaterial(eBaseItemType_pockettool,	eMaterial_undefined)->setIconName(L"lead")->setDescriptionId(IDS_ITEM_LEAD)->setUseDescriptionId(IDS_DESC_LEAD);
	Item::nameTag = (new NameTagItem(165))															->setIconName(L"name_tag")->setDescriptionId(IDS_ITEM_NAME_TAG)->setUseDescriptionId(IDS_DESC_NAME_TAG);

	//mod items
	Item::netheriteIngot = (new Item(166))
    ->setBaseItemTypeAndMaterial(eBaseItemType_treasure, eMaterial_undefined)
    ->setIconName(L"ingotNetherite")
    ->setDescriptionId(IDS_ITEM_NETHERITE_INGOT)
    ->setUseDescriptionId(IDS_DESC_DIAMONDS);
}
// 4J Stu - We need to do this after the staticCtor AND after staticCtors for other class
// eg Recipes
void Item::staticInit()
{
	Stats::buildItemStats();
}


_Tier::Tier(int level, int uses, float speed, float damage, int enchantmentValue) :
level( level ),
	uses( uses ),
	speed( speed ),
	damage( damage ),
	enchantmentValue( enchantmentValue )
{
}


int _Tier::getUses() const
{
	return uses;
}

float _Tier::getSpeed() const
{
	return speed;
}

float _Tier::getAttackDamageBonus() const
{
	return damage;
}

int _Tier::getLevel() const
{
	return level;
}

int _Tier::getEnchantmentValue() const
{
	return enchantmentValue;
}

int _Tier::getTierItemId() const
{
	if (this == Tier::WOOD)
	{
		return Tile::wood_Id;
	}
	else if (this == Tier::STONE)
	{
		return Tile::cobblestone_Id;
	}
	else if (this == Tier::GOLD)
	{
		return Item::goldIngot_Id;
	}
	else if (this == Tier::IRON)
	{
		return Item::ironIngot_Id;
	}
	else if (this == Tier::DIAMOND)
	{
		return Item::diamond_Id;
	}
	return 0;
}

Item::Item(int id) : id( 256 + id )
{
	maxStackSize = Item::MAX_STACK_SIZE;
	maxDamage = 0;
	icon = nullptr;
	m_handEquipped = false;
	m_isStackedByData = false;

	craftingRemainingItem = nullptr;
	potionBrewingFormula = L"";

	m_iMaterial=eMaterial_undefined;
	m_iBaseItemType=eBaseItemType_undefined;
	m_textureName = L"";

	// TODO Init this string
	//string descriptionId;

	//this->id = 256 + id;
	if (items[256 + id] != nullptr)
	{
		app.DebugPrintf("CONFLICT @ %d" , id);
	}

	items[256 + id] = this;
}

wstring Item::getItemSID(int id)
{
	auto it = itemSID.find(id);
	return it != itemSID.end() ? it->second : L"unknown";
}
// 4J-PB - adding so we can class different items together for the new crafting menu
// so pickaxe_stone would get tagged with pickaxe and stone
Item *Item::setBaseItemTypeAndMaterial(int iType,int iMaterial)
{
	this->m_iBaseItemType = iType;
	this->m_iMaterial = iMaterial;
	return this;
}

int Item::getBaseItemType()
{
	return this->m_iBaseItemType;
}

int Item::getMaterial()
{
	return this->m_iMaterial;
}

Item *Item::setIconName(const wstring &name)
{
	m_textureName = name;

	return this;
}

wstring Item::getIconName()
{
	return m_textureName;
}

Item *Item::setMaxStackSize(int max)
{
	maxStackSize = max;
	return this;
}

int Item::getIconType()
{
	return Icon::TYPE_ITEM;
}

Icon *Item::getIcon(int auxValue)
{
	return icon;
}

Icon *Item::getIcon(shared_ptr<ItemInstance> itemInstance)
{
	return getIcon(itemInstance->getAuxValue());
}

bool Item::useOn(shared_ptr<ItemInstance> itemInstance, shared_ptr<Player> player, Level *level, int x, int y, int z, int face, float clickX, float clickY, float clickZ, bool bTestUseOnOnly)
{
	return false;
}

float Item::getDestroySpeed(shared_ptr<ItemInstance> itemInstance, Tile *tile)
{
	return 1;
}

bool Item::TestUse(shared_ptr<ItemInstance> itemInstance, Level *level, shared_ptr<Player> player)
{
	return false;
}

shared_ptr<ItemInstance> Item::use(shared_ptr<ItemInstance> itemInstance, Level *level, shared_ptr<Player> player)
{
	return itemInstance;
}

shared_ptr<ItemInstance> Item::useTimeDepleted(shared_ptr<ItemInstance> itemInstance, Level *level, shared_ptr<Player> player)
{
	return itemInstance;
}

int Item::getMaxStackSize() const
{
	return maxStackSize;
}

int Item::getLevelDataForAuxValue(int auxValue)
{
	return 0;
}

bool Item::isStackedByData()
{
	return m_isStackedByData;
}


Item *Item::setStackedByData(bool isStackedByData)
{
	this->m_isStackedByData = isStackedByData;
	return this;
}


int Item::getMaxDamage()
{
	return maxDamage;
}


Item *Item::setMaxDamage(int maxDamage)
{
	this->maxDamage = maxDamage;
	return this;
}


bool Item::canBeDepleted()
{
	return maxDamage > 0 && !m_isStackedByData;
}

/**
* Returns true when the item was used to deal more than default damage
*
* @param itemInstance
* @param mob
* @param attacker
* @return
*/
bool Item::hurtEnemy(shared_ptr<ItemInstance> itemInstance, shared_ptr<LivingEntity> mob, shared_ptr<LivingEntity> attacker)
{
	return false;
}

/**
* Returns true when the item was used to mine more efficiently
*
* @param itemInstance
* @param tile
* @param x
* @param y
* @param z
* @param owner
* @return
*/
bool Item::mineBlock(shared_ptr<ItemInstance> itemInstance, Level *level, int tile, int x, int y, int z, shared_ptr<LivingEntity> owner)
{
	return false;
}

int Item::getAttackDamage(shared_ptr<Entity> entity)
{
	return 1;
}

bool Item::canDestroySpecial(Tile *tile)
{
	return false;
}

bool Item::interactEnemy(shared_ptr<ItemInstance> itemInstance, shared_ptr<Player> player, shared_ptr<LivingEntity> mob)
{
	return false;
}

Item *Item::handEquipped()
{
	m_handEquipped = true;
	return this;
}

bool Item::isHandEquipped()
{
	return m_handEquipped;
}

bool Item::isMirroredArt()
{
	return false;
}

Item *Item::setDescriptionId(unsigned int id)
{
	this->descriptionId = id;
	return this;
}

LPCWSTR Item::getDescription()
{
	return app.GetString(getDescriptionId());
	//return I18n::get(getDescriptionId());
}

LPCWSTR Item::getDescription(shared_ptr<ItemInstance> instance)
{
	return app.GetString(getDescriptionId(instance));
	//return I18n::get(getDescriptionId(instance));
}

unsigned int Item::getDescriptionId(int iData /*= -1*/)
{
	return descriptionId;
}

unsigned int Item::getDescriptionId(shared_ptr<ItemInstance> instance)
{
	return descriptionId;
}

Item *Item::setUseDescriptionId(unsigned int id)
{
	this->useDescriptionId = id;
	return this;
}

unsigned int Item::getUseDescriptionId()
{
	return useDescriptionId;
}

unsigned int Item::getUseDescriptionId(shared_ptr<ItemInstance> instance)
{
	return useDescriptionId;
}

Item *Item::setCraftingRemainingItem(Item *craftingRemainingItem)
{
	this->craftingRemainingItem = craftingRemainingItem;
	return this;
}

bool Item::shouldMoveCraftingResultToInventory(shared_ptr<ItemInstance> instance)
{
	// Default is good for the vast majority of items
	return true;
}

bool Item::shouldOverrideMultiplayerNBT()
{
	return true;
}

Item *Item::getCraftingRemainingItem()
{
	return craftingRemainingItem;
}

bool Item::hasCraftingRemainingItem()
{
	return craftingRemainingItem != nullptr;
}

wstring Item::getName()
{
	return L"";//I18n::get(getDescriptionId() + L".name");
}

int Item::getColor(shared_ptr<ItemInstance> item, int spriteLayer)
{
	return 0xffffff;
}

void Item::inventoryTick(shared_ptr<ItemInstance> itemInstance, Level *level, shared_ptr<Entity> owner, int slot, bool selected) {
}

void Item::onCraftedBy(shared_ptr<ItemInstance> itemInstance, Level *level, shared_ptr<Player> player)
{
}

bool Item::isComplex()
{
	return false;
}

UseAnim Item::getUseAnimation(shared_ptr<ItemInstance> itemInstance)
{
	return UseAnim_none;
}

int Item::getUseDuration(shared_ptr<ItemInstance> itemInstance)
{
	return 0;
}

void Item::releaseUsing(shared_ptr<ItemInstance> itemInstance, Level *level, shared_ptr<Player> player, int durationLeft)
{
}

Item *Item::setPotionBrewingFormula(const wstring &potionBrewingFormula)
{
	this->potionBrewingFormula = potionBrewingFormula;
	return this;
}

wstring Item::getPotionBrewingFormula()
{
	return potionBrewingFormula;
}

bool Item::hasPotionBrewingFormula()
{
	return !potionBrewingFormula.empty();
}

void Item::appendHoverText(shared_ptr<ItemInstance> itemInstance, shared_ptr<Player> player, vector<HtmlString> *lines, bool advanced)
{
}

wstring Item::getHoverName(shared_ptr<ItemInstance> itemInstance)
{
	//String elementName = ("" + Language.getInstance().getElementName(getDescription(itemInstance))).trim();
	//return elementName;
	return app.GetString(getDescriptionId(itemInstance));
}

bool Item::isFoil(shared_ptr<ItemInstance> itemInstance)
{
	if (itemInstance->isEnchanted()) return true;
	return false;
}

const Rarity *Item::getRarity(shared_ptr<ItemInstance> itemInstance)
{
	if (itemInstance->isEnchanted()) return Rarity::rare;
	return Rarity::common;
}

bool Item::isEnchantable(shared_ptr<ItemInstance> itemInstance)
{
	return getMaxStackSize() == 1 && canBeDepleted();
}

HitResult *Item::getPlayerPOVHitResult(Level *level, shared_ptr<Player> player, bool alsoPickLiquid)
{
	float a = 1;

	float xRot = player->xRotO + (player->xRot - player->xRotO) * a;
	float yRot = player->yRotO + (player->yRot - player->yRotO) * a;


	double x = player->xo + (player->x - player->xo) * a;
	double y = player->yo + (player->y - player->yo) * a + 1.62 - player->heightOffset;
	double z = player->zo + (player->z - player->zo) * a;

	Vec3 *from = Vec3::newTemp(x, y, z);

	float yCos = (float) cos(-yRot * Mth::RAD_TO_GRAD - PI);
	float ySin = (float) sin(-yRot * Mth::RAD_TO_GRAD - PI);
	float xCos = (float) -cos(-xRot * Mth::RAD_TO_GRAD);
	float xSin = (float) sin(-xRot * Mth::RAD_TO_GRAD);

	float xa = ySin * xCos;
	float ya = xSin;
	float za = yCos * xCos;

	double range = 5;
	Vec3 *to = from->add(xa * range, ya * range, za * range);
	return level->clip(from, to, alsoPickLiquid, !alsoPickLiquid);
}

int Item::getEnchantmentValue()
{
	return 0;
}

bool Item::hasMultipleSpriteLayers()
{
	return false;
}

Icon *Item::getLayerIcon(int auxValue, int spriteLayer)
{
	return getIcon(auxValue);
}

bool Item::mayBePlacedInAdventureMode()
{
	return true;
}

bool Item::isValidRepairItem(shared_ptr<ItemInstance> source, shared_ptr<ItemInstance> repairItem)
{
	return false;
}

void Item::registerIcons(IconRegister *iconRegister)
{
	icon = iconRegister->registerIcon(m_textureName);
}

attrAttrModMap *Item::getDefaultAttributeModifiers()
{
	return new attrAttrModMap();
}


/*
	4J: These are necesary on the PS3.
		(and 4 and Vita).
*/
#if (defined __PS3__ || defined __ORBIS__ || defined __PSVITA__)
const int Item::shovel_iron_Id		;
const int Item::pickAxe_iron_Id		;
const int Item::hatchet_iron_Id		;
const int Item::flintAndSteel_Id	;
const int Item::apple_Id			;
const int Item::bow_Id				;
const int Item::arrow_Id			;
const int Item::coal_Id				;
const int Item::diamond_Id			;
const int Item::ironIngot_Id		;
const int Item::goldIngot_Id		;
const int Item::sword_iron_Id		;
const int Item::sword_wood_Id		;
const int Item::shovel_wood_Id		;
const int Item::pickAxe_wood_Id		;
const int Item::hatchet_wood_Id		;
const int Item::sword_stone_Id		;
const int Item::shovel_stone_Id		;
const int Item::pickAxe_stone_Id	;
const int Item::hatchet_stone_Id	;
const int Item::sword_diamond_Id	;
const int Item::shovel_diamond_Id	;
const int Item::pickAxe_diamond_Id	;
const int Item::hatchet_diamond_Id	;
const int Item::stick_Id			;
const int Item::bowl_Id				;
const int Item::mushroomStew_Id		;
const int Item::sword_gold_Id		;
const int Item::shovel_gold_Id		;
const int Item::pickAxe_gold_Id		;
const int Item::hatchet_gold_Id		;
const int Item::string_Id			;
const int Item::feather_Id			;
const int Item::gunpowder_Id		;
const int Item::hoe_wood_Id			;
const int Item::hoe_stone_Id		;
const int Item::hoe_iron_Id			;
const int Item::hoe_diamond_Id		;
const int Item::hoe_gold_Id			;
const int Item::seeds_wheat_Id		;
const int Item::wheat_Id			;
const int Item::bread_Id			;
const int Item::helmet_leather_Id		;
const int Item::chestplate_leather_Id	;
const int Item::leggings_leather_Id	;
const int Item::boots_leather_Id		;
const int Item::helmet_chain_Id		;
const int Item::chestplate_chain_Id	;
const int Item::leggings_chain_Id	;
const int Item::boots_chain_Id		;
const int Item::helmet_iron_Id		;
const int Item::chestplate_iron_Id	;
const int Item::leggings_iron_Id	;
const int Item::boots_iron_Id		;
const int Item::helmet_diamond_Id	;
const int Item::chestplate_diamond_Id;
const int Item::leggings_diamond_Id	;
const int Item::boots_diamond_Id	;
const int Item::helmet_gold_Id		;
const int Item::chestplate_gold_Id	;
const int Item::leggings_gold_Id	;
const int Item::boots_gold_Id		;
const int Item::flint_Id			;
const int Item::porkChop_raw_Id		;
const int Item::porkChop_cooked_Id	;
const int Item::painting_Id			;
const int Item::apple_gold_Id		;
const int Item::sign_Id				;
const int Item::door_wood_Id			;
const int Item::bucket_empty_Id		;
const int Item::bucket_water_Id		;
const int Item::bucket_lava_Id		;
const int Item::minecart_Id			;
const int Item::saddle_Id			;
const int Item::door_iron_Id			;
const int Item::redStone_Id			;
const int Item::snowBall_Id			;
const int Item::boat_Id				;
const int Item::leather_Id			;
const int Item::bucket_milk_Id				;
const int Item::brick_Id				;
const int Item::clay_Id				;
const int Item::reeds_Id				;
const int Item::paper_Id				;
const int Item::book_Id				;
const int Item::slimeBall_Id			;
const int Item::minecart_chest_Id	;
const int Item::minecart_furnace_Id	;
const int Item::egg_Id				;
const int Item::compass_Id			;
const int Item::fishingRod_Id		;
const int Item::clock_Id				;
const int Item::yellowDust_Id		;
const int Item::fish_raw_Id			;
const int Item::fish_cooked_Id		;
const int Item::dye_powder_Id		;
const int Item::bone_Id				;
const int Item::sugar_Id				;
const int Item::cake_Id				;
const int Item::bed_Id				;
const int Item::repeater_Id				;
const int Item::cookie_Id			;
const int Item::map_Id				;
const int Item::shears_Id			;
const int Item::melon_Id				;
const int Item::seeds_pumpkin_Id		;
const int Item::seeds_melon_Id		;
const int Item::beef_raw_Id			;
const int Item::beef_cooked_Id		;
const int Item::chicken_raw_Id		;
const int Item::chicken_cooked_Id	;
const int Item::rotten_flesh_Id		;
const int Item::enderPearl_Id		;
const int Item::blazeRod_Id			;
const int Item::ghastTear_Id			;
const int Item::goldNugget_Id		;
const int Item::netherwart_seeds_Id;
const int Item::potion_Id			;
const int Item::glassBottle_Id		;
const int Item::spiderEye_Id			;
const int Item::fermentedSpiderEye_Id;
const int Item::blazePowder_Id		;
const int Item::magmaCream_Id		;
const int Item::brewingStand_Id		;
const int Item::cauldron_Id			;
const int Item::eyeOfEnder_Id		;
const int Item::speckledMelon_Id		;
const int Item::spawnEgg_Id;
const int Item::expBottle_Id			;
const int Item::skull_Id				;
const int Item::record_01_Id			;
const int Item::record_02_Id			;
const int Item::record_03_Id			;
const int Item::record_04_Id			;
const int Item::record_05_Id			;
const int Item::record_06_Id			;
const int Item::record_07_Id			;
const int Item::record_09_Id			;
const int Item::record_10_Id		    ;
const int Item::record_11_Id		    ;
const int Item::record_12_Id			;
const int Item::record_08_Id			;
const int Item::fireball_Id			;
const int Item::itemFrame_Id			;
const int Item::netherbrick_Id		;
const int Item::emerald_Id			;
const int Item::flowerPot_Id			;
const int Item::carrots_Id			;
const int Item::potato_Id			;
const int Item::potatoBaked_Id		;
const int Item::potatoPoisonous_Id	;
const int Item::carrotGolden_Id		;
const int Item::carrotOnAStick_Id	;
const int Item::pumpkinPie_Id		;
const int Item::enchantedBook_Id		;
const int Item::netherQuartz_Id		;
#endif
