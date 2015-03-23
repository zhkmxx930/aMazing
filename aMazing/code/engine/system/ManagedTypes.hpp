#pragma once

enum MANAGED_DEVICE_TYPE
{
	DEFAULT_DEVICE,
};
enum MANAGED_CONTEXT_TYPE
{
	DEFAULT_CONTEXT,
	IMMEDIATE_CONTEXT, // as default
	DEFFERED_CONTEXT,
};

enum MANAGED_DEPTH_STENCIL_VIEW_TYPE
{
	DEFAULT_DEPTH_STENCIL_VIEW,
};


enum MANAGED_SAMPLER_TYPE
{
	DEFAULT_SAMPLER,
	LINEAR_SAMPLER, //as default
	POINT_SAMPLER,
};