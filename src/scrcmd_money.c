#include "scrcmd.h"
#include "player_data.h"

BOOL ScrCmd_AddMoney(SCRIPTCONTEXT* ctx) {
    SAVEDATA* savedata = ScriptEnvironment_GetSav2Ptr(ctx->unk80);
    PLAYERPROFILE* profile = Sav2_PlayerData_GetProfileAddr(savedata);

    u32 amount = ScriptReadWord(ctx);
    PlayerProfile_AddMoney(profile, amount);

    return FALSE;
}

BOOL ScrCmd_SubMoneyImmediate(SCRIPTCONTEXT* ctx) {
    SAVEDATA* savedata = ScriptEnvironment_GetSav2Ptr(ctx->unk80);
    PLAYERPROFILE* profile = Sav2_PlayerData_GetProfileAddr(savedata);

    u32 amount = ScriptReadWord(ctx);
    PlayerProfile_SubMoney(profile, amount);

    return FALSE;
}

BOOL ScrCmd_SubMoneyVar(SCRIPTCONTEXT* ctx) {
    SAVEDATA* savedata = ScriptEnvironment_GetSav2Ptr(ctx->unk80);
    PLAYERPROFILE* profile = Sav2_PlayerData_GetProfileAddr(savedata);

    u16 amount = VarGet(ctx->unk80, ScriptReadHalfword(ctx));
    PlayerProfile_SubMoney(profile, amount);

    return FALSE;
}

BOOL ScrCmd_HasEnoughMoneyImmediate(SCRIPTCONTEXT* ctx) {
    SAVEDATA* savedata = ScriptEnvironment_GetSav2Ptr(ctx->unk80);
    PLAYERPROFILE* profile = Sav2_PlayerData_GetProfileAddr(savedata);
    u16* ret_ptr = GetVarPointer(ctx->unk80, ScriptReadHalfword(ctx));

    u32 amount = ScriptReadWord(ctx);
    u32 money = PlayerProfile_GetMoney(profile);
    if (money < amount) {
        *ret_ptr = FALSE;
    } else {
        *ret_ptr = TRUE;
    }

    return FALSE;
}

BOOL ScrCmd_HasEnoughMoneyVar(SCRIPTCONTEXT* ctx) {
    SAVEDATA* savedata = ScriptEnvironment_GetSav2Ptr(ctx->unk80);
    PLAYERPROFILE* profile = Sav2_PlayerData_GetProfileAddr(savedata);
    u16* ret_ptr = GetVarPointer(ctx->unk80, ScriptReadHalfword(ctx));

    u16 amount = VarGet(ctx->unk80, ScriptReadHalfword(ctx));
    u32 money = PlayerProfile_GetMoney(profile);
    if (money < amount) {
        *ret_ptr = FALSE;
    } else {
        *ret_ptr = TRUE;
    }

    return FALSE;
}