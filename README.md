
# BlåhajDB - BGX

A better wrapper for BGX!

**Changelogs and Mentions (on update) are available** https://discord.gg/czsJYCYSn8




## API Reference

Please include 'SpellDB.h' before anything else!
```cpp
  #include "SpellDB.h"
```

## /!\ NECESSARY! /!\
#### **Initializing Menus**

```cpp
  Database::InitializeCancelMenu(tab);
  Database::InitializeBuffMenu(tab);
``` 

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `tab` | `TreeTab*` | **Required**. Pre-Created Tab |

#### **Active Spell Database (Channeling/Cancel)**

```cpp
  Database::canCancel(target);
```

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `target` | `game_object_script` | **Required**. Target to check |

#### **Ally Buff Database**

```cpp
  Database::canOnAllyBuff(hash);
```

| Parameter | Type     | Description                       |
| :-------- | :------- | :-------------------------------- |
| `hash`      | `uint_32t` | **Required**. Hash of a spell |


## FAQ

#### How to use the Active Spell Database?

You can either:

- Iterate through enemy champions OnUpdate() (recommended)
- Use OnProcessSpellCast


#### How to use the Ally Buff Database?

You can either:

- Iterate through ally champions bufflist OnUpdate() (recommended)
- Use OnBuffGain


## SDK Calls

 - [OnUpdate](https://github.com/BGXGG/SDK/blob/main/plugin_sdk.hpp#L3504)
 - [OnProcessSpellCast](https://github.com/BGXGG/SDK/blob/main/plugin_sdk.hpp#L3560)
 - [OnBuffGain](https://github.com/BGXGG/SDK/blob/main/plugin_sdk.hpp#L3623)

