#pragma once

#include "CoreMinimal.h"
#include "FSpeckleBranch.generated.h"


/*
* Struct that holds all the properties required
* from a speckle Branch
* received from GraphQL.
*/
USTRUCT(BlueprintType)
struct FSpeckleBranch
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	FString ID;

	UPROPERTY(BlueprintReadWrite)
	FString Name;

	UPROPERTY(BlueprintReadWrite)
	FString Description;

	UPROPERTY(BlueprintReadWrite)
	FString Author;

	UPROPERTY(BlueprintReadWrite)
	FString Commits;

	FSpeckleBranch(){};
	
	FSpeckleBranch(const FString& ID, const FString& Name, const FString& Description):
		ID(ID), Name(Name), Description(Description){}
	
	FSpeckleBranch(const FString& ID, const FString& Name, const FString& Description, const FString& Author, const FString& Commits):
		ID(ID), Name(Name), Description(Description), Author(Author), Commits(Commits){}
};