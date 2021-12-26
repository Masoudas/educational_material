"""
There are four key elements in this example:

A @dataclass describes the application's configuration ConfigStore manages the Structured Config
cfg is duck typed as a MySQLConfig instead of a DictConfig. There is a subtle typo in the code below, can you spot it?

In this example, the config node stored in the ConfigStore replaces the traditional config.yaml file. (Notice that a registration is added essentially to the whole thing, to return a type as we define it. We later show that we can use nested types as well.)


from dataclasses import dataclass

import hydra
from hydra.core.config_store import ConfigStore

@dataclass
class MySQLConfig:
    host: str = "localhost"
    port: int = 3306

cs = ConfigStore.instance()
# Registering the Config class with the name 'config'.
cs.store(name="config", node=MySQLConfig)

@hydra.main(config_path=None, config_name="config")
def my_app(cfg: MySQLConfig) -> None:
    # pork should be port!
    if cfg.pork == 80:
        print("Is this a webserver?!")

if __name__ == "__main__":
    my_app()
"""