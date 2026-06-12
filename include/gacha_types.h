#pragma once
#include <string>
#include <vector>

// 抽卡类型枚举
enum class GachaType {
    CHARACTER,      // 角色池
    WEAPON,         // 武器池
    PERMANENT,      // 常驻池
};

enum class RarityLevel {
    THREE_STAR = 3,
    FOUR_STAR = 4,
    FIVE_STAR = 5,
};

// 卡池信息结构体
struct GachaPool {
    std::string name;           // 卡池名称
    std::string character;      // 限定角色
    std::string weapon;         // 限定武器
    std::string color;          // 显示颜色代码
    GachaType type;             // 卡池类型
};

// 抽卡结果结构体
struct GachaResult {
    std::string name;           // 获得物品名称
    int pity;                   // 当前保底进度
    RarityLevel rarity;         // 稀有度
    bool is_guaranteed;         // 是否歪了
};

// 5星统计记录
struct FiveStarRecord {
    std::string name;           // 物品名称
    int pity;                   // 保底进度
    bool is_guaranteed;         // 是否歪了
};
