USE [HelivaluesSQL]
GO

/****** Object:  Table [dbo].[engine_power_revamp]    Script Date: 2/28/2013 8:20:44 AM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[engine_power_revamp](
	[engine_power_id] [int] IDENTITY(1,1) NOT NULL,
	[engine_id] [int] NULL,
	[takeoff] [nvarchar](255) NULL,
	[takeoff_metric] [nvarchar](255) NULL,
	[max_continuous] [nvarchar](255) NULL,
	[max_continuous_metric] [nvarchar](255) NULL,
	[oei_30_second] [nvarchar](255) NULL,
	[oei_30_second_metric] [nvarchar](255) NULL,
	[oei_2_minute] [nvarchar](255) NULL,
	[oei_2_minute_metric] [nvarchar](255) NULL,
	[oei_2_5_minute] [nvarchar](255) NULL,
	[oei_2_5_minute_metric] [nvarchar](255) NULL,
	[oei_30_minute] [nvarchar](255) NULL,
	[oei_30_minute_metric] [nvarchar](255) NULL,
	[oei_continuous] [nvarchar](255) NULL,
	[oei_continuous_metric] [nvarchar](255) NULL,
	[additional_1_label] [nvarchar](255) NULL,
	[additional_1] [nvarchar](255) NULL,
	[additional_1_metric] [nvarchar](255) NULL,
	[additional_2_label] [nvarchar](255) NULL,
	[additional_2] [nvarchar](255) NULL,
	[additional_2_metric] [nvarchar](255) NULL,
	[additional_3_label] [nvarchar](255) NULL,
	[additional_3] [nvarchar](255) NULL,
	[additional_3_metric] [nvarchar](255) NULL,
	[entered_date] [datetime] NULL,
	[entered_user] [nvarchar](255) NULL,
	[oei_5_minute] [nvarchar](255) NULL,
	[oei_5_minute_metric] [nvarchar](255) NULL
) ON [PRIMARY]

GO