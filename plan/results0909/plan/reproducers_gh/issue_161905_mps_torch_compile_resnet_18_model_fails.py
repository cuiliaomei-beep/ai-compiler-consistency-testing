# source: https://github.com/pytorch/pytorch/issues/161905
# title: [MPS] `torch.compile` ResNet-18 model fails during `loss.backward()` on MPS backend, but works on CPU
# state: closed  created: 2025-09-01
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.optim as optim
from torch import Tensor
from typing import Type, Any, Callable, Union, List, Optional
from torchvision.models.resnet import resnet18


BATCH_SIZE = 4
NUM_CLASSES = 10
LEARNING_RATE = 0.01
device='mps'

model = resnet18(num_classes=NUM_CLASSES)

criterion = nn.CrossEntropyLoss()
optimizer = optim.SGD(model.parameters(), lr=LEARNING_RATE)

model=model.to(device)
model.train() 

@torch.compile
def train(images,labels):
    images=images.to(device)
    labels=labels.to(device)
    
    optimizer.zero_grad()

    outputs = model(images)
    loss = criterion(outputs, labels)
    loss.backward()
    optimizer.step()

images = torch.randn(BATCH_SIZE, 3, 224, 224)
labels = torch.randint(0, NUM_CLASSES, (BATCH_SIZE,))

train(images,labels)
