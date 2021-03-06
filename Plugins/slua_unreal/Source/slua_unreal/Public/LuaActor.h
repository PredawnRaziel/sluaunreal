// Tencent is pleased to support the open source community by making sluaunreal available.

// Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.
// Licensed under the BSD 3-Clause License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at

// https://opensource.org/licenses/BSD-3-Clause

// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.


#pragma once
#include "CoreMinimal.h"
#include "LuaState.h"
#include "LuaBase.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "GameFramework/GameModeBase.h"
#include "LuaBlueprintLibrary.h"
#include "LuaActor.generated.h"

#define LUABASE_BODY(NAME) \
protected: \
	virtual void BeginPlay() override { \
	if (!init(this, #NAME, LuaStateName, LuaFilePath)) return; \
		Super::BeginPlay(); \
		PrimaryActorTick.SetTickFunctionEnable(postInit("bCanEverTick")); \
	} \
	virtual void Tick(float DeltaTime) override { \
		tick(DeltaTime); \
	} \
public:	\
	virtual void ProcessEvent(UFunction* func, void* params) override { \
	if (luaImplemented(func, params))  \
		return; \
		Super::ProcessEvent(func, params); \
	} \
	void SuperTick() { \
		Super::Tick(deltaTime); \
	} \

using slua_Luabase = slua::LuaBase;

UCLASS()
class SLUA_UNREAL_API ALuaActor : public AActor, public slua_Luabase {
	GENERATED_BODY()
	LUABASE_BODY(LuaActor)
public:
	ALuaActor()
		: AActor() 
	{
		PrimaryActorTick.bCanEverTick = true;
	}
	ALuaActor(const FObjectInitializer& ObjectInitializer) 
		: AActor(ObjectInitializer) 
	{
		PrimaryActorTick.bCanEverTick = true;
	}
public:
	// below UPROPERTY and UFUNCTION can't be put to macro LUABASE_BODY
	// so copy & paste them
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua") 
	FString LuaFilePath;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaStateName;
	UFUNCTION(BlueprintCallable, Category = "slua")
	FLuaBPVar CallLuaMember(FString FunctionName, const TArray<FLuaBPVar>& Args) {
		return callMember(FunctionName, Args);
	}
};

UCLASS()
class SLUA_UNREAL_API ALuaPawn : public APawn, public slua_Luabase {
	GENERATED_BODY()
	LUABASE_BODY(LuaPawn)
public:
	ALuaPawn(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) 
		: APawn(ObjectInitializer)
	{
		PrimaryActorTick.bCanEverTick = true;
	}
public:
	// below UPROPERTY and UFUNCTION can't be put to macro LUABASE_BODY
	// so copy & paste them
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaFilePath;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaStateName;
	UFUNCTION(BlueprintCallable, Category = "slua")
	FLuaBPVar CallLuaMember(FString FunctionName, const TArray<FLuaBPVar>& Args) {
		return callMember(FunctionName, Args);
	}
};

UCLASS()
class SLUA_UNREAL_API ALuaCharacter : public ACharacter, public slua_Luabase {
	GENERATED_BODY()
	LUABASE_BODY(LuaCharacter)
public:
	ALuaCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get())
		: ACharacter(ObjectInitializer)
	{
		PrimaryActorTick.bCanEverTick = true;
	}
public:
	// below UPROPERTY and UFUNCTION can't be put to macro LUABASE_BODY
	// so copy & paste them
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaFilePath;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaStateName;
	UFUNCTION(BlueprintCallable, Category = "slua")
	FLuaBPVar CallLuaMember(FString FunctionName, const TArray<FLuaBPVar>& Args) {
		return callMember(FunctionName, Args);
	}
};

UCLASS()
class SLUA_UNREAL_API ALuaController : public AController, public slua_Luabase {
	GENERATED_BODY()
	LUABASE_BODY(LuaController)
public:
	ALuaController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get())
		: AController(ObjectInitializer)
	{
		PrimaryActorTick.bCanEverTick = true;
	}
public:
	// below UPROPERTY and UFUNCTION can't be put to macro LUABASE_BODY
	// so copy & paste them
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaFilePath;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaStateName;
	UFUNCTION(BlueprintCallable, Category = "slua")
	FLuaBPVar CallLuaMember(FString FunctionName, const TArray<FLuaBPVar>& Args) {
		return callMember(FunctionName, Args);
	}
};

UCLASS()
class SLUA_UNREAL_API ALuaPlayerController : public APlayerController, public slua_Luabase {
	GENERATED_BODY()
	LUABASE_BODY(LuaPlayerController)
public:
	ALuaPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get())
		: APlayerController(ObjectInitializer)
	{
		PrimaryActorTick.bCanEverTick = true;
	}
public:
	// below UPROPERTY and UFUNCTION can't be put to macro LUABASE_BODY
	// so copy & paste them
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaFilePath;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaStateName;
	UFUNCTION(BlueprintCallable, Category = "slua")
	FLuaBPVar CallLuaMember(FString FunctionName, const TArray<FLuaBPVar>& Args) {
		return callMember(FunctionName, Args);
	}
};

UCLASS()
class SLUA_UNREAL_API ALuaGameModeBase : public AGameModeBase, public slua_Luabase {
	GENERATED_BODY()
	LUABASE_BODY(LuaGameModeBase)
public:
	// below UPROPERTY and UFUNCTION can't be put to macro LUABASE_BODY
	// so copy & paste them
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaFilePath;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "slua")
	FString LuaStateName;
	UFUNCTION(BlueprintCallable, Category = "slua")
	FLuaBPVar CallLuaMember(FString FunctionName, const TArray<FLuaBPVar>& Args) {
		return callMember(FunctionName, Args);
	}
};

